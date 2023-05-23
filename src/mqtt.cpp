#include "mqtt.h"
#include "domain.h"

MQTTClient *MQTTClient::instance = nullptr;
Domain domain;

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
    // Forward the callback to the actual member function
    MQTTClient::instance->callback(topic, payload, length);
}

void MQTTClient::callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    int uuidLength = this->uuid.length();
    char uuidCharArray[37];
    uuid.toCharArray(uuidCharArray, sizeof(uuidCharArray));

    // Parse JSON data
    Serial.println("test1");
    DynamicJsonDocument doc(1024);
    Serial.println("test2");
    DeserializationError error = deserializeJson(doc, payload, length);
    Serial.println("test3");

    if (error)
    {
        Serial.println("test4");
        Serial.print("JSON parsing error: ");
        Serial.println(error.c_str());
        return;
    }
    Serial.println("test5");

    Serial.println(uuidCharArray);
    Serial.println(this->uuid);
    Serial.println("test6");

    // Forward topic data to respective function

    // Check if message is on init-session topic
    if (strcmp(topic, strcat(uuidCharArray, SESSION_INIT)) == 0)
    {
        // get each json field and send them separately to domain

        // Serial.print("p_max was: ");
        // Serial.println(domain.pMax);

        // float max_power = doc["max_power"];
        // domain.setPMax(max_power);
        // // p_max = max_power;
        // // p_tmax = max_power;
        // Serial.print("p_max set to: ");
        // Serial.println(domain.pMax);
    }
    Serial.println("test7");

    // Check if message is on update-session topic
    if (strcmp(topic, strcat(uuidCharArray, "commands/update-session")) == 0)
    {
        // int max_power = doc["max_power"];
        // int duration = doc["duration"];
        // p_tmax = max_power;
        // timeout = duration * 1000;
        // start_time = millis();
        // Serial.print("p_tmax set to: ");
        // Serial.println(p_tmax);
        // Serial.print("timeout set to: ");
        // Serial.println(timeout);
    }
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