#include "mqtt.h"
// #include "domain.h"

MQTTClient *MQTTClient::instance = nullptr;
// Domain domain;

void MQTTClient::initWifiConnection(const char *ssid, const char *password)
{
    connectToWifi(ssid, password);
}

void MQTTClient::connect(const char *brokerUrl, int port, const char *username, const char *password, const char *certificate)
{
    espClient.setCACert(certificate);
    client.setServer(brokerUrl, port);
    client.setBufferSize(BUFFER_SIZE);

    MQTTClient::instance = this;

    client.setCallback(staticCallback);

    while (!client.connected())
    {
        Serial.print("Connecting to MQTT broker...");

        if (client.connect(CLIENT_NAME, username, password))
        {
            String topic;
            Serial.println("Connected!");

            if (this->uuid)
            {
                for (int i = 0; i < readTopicCount; i++)
                {
                    topic = this->uuid + READ_TOPICS[i];
                    Serial.println("Subscribing to ");
                    Serial.println(topic);
                    Serial.println(client.subscribe(topic.c_str()));
                }
            }
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

// MQTT Callback function for handling received messages
void MQTTClient::staticCallback(char *topic, byte *payload, unsigned int length)
{
    // Forward the callback to the actual function
    MQTTClient::instance->actions.processMessage(MQTTClient::instance->uuid, topic, payload, length);
}

void MQTTClient::checkReconnect()
{
    if (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");

        if (client.connect(CLIENT_NAME))
        {
            Serial.println("Connected!");

            for (int i = 0; i < readTopicCount; i++)
            {
                String topic = this->uuid + READ_TOPICS[i];
                Serial.println("Subscribing to ");
                Serial.println(topic);
                Serial.println(client.subscribe(topic.c_str()));
            }
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            Serial.println(" Retrying in 5 seconds...");
            delay(5000);
        }
    }
}

void MQTTClient::loop()
{
    client.loop();
}

void MQTTClient::publish(const char *topic, const char *message)
{
    String topicWithUuid;
    topicWithUuid = this->uuid + TOPIC_DELIMITER + topic;
    Serial.println("Publishing to ");
    Serial.println(topicWithUuid);

    client.publish(topicWithUuid.c_str(), message);
}