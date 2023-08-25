#include "mqtt.h"
// #include "domain.h"

const int PIN_REL1 = 2; // Replace with the desired pin number
const int PIN_REL2 = 4; // Replace with the desired pin number

const char *SESSION_INIT = "/commands/session-init";
const char *SESSION_STOP = "/commands/session-stop";
const char *FUNCTION_PARAMS = "/commands/function-parameters";
const char *PTMAX = "/commands/ptmax";
const char *REVERT_TO_DEFAULT = "/commands/revert-to-default";
const char *ENERGY_DELIVERY_START = "/commands/energy-delivery-start";
const char *ENERGY_DELIVERY_STOP = "/commands/energy-delivery-stop";
const char *ELECTRICITY_DATA_INTERVAL = "/commands/electricity-data-interval";
const char *RELAY_TEST_ON = "/commands/relay-test-on";
const char *RELAY_TEST_OFF = "/commands/relay-test-off";
const char *RELAY_TEST_KICK = "/commands/relay-test-kick";

const char *ELECTRICITY_DATA = "electricity-data";
const char *POWER_EXCEEDED = "power-exceeded";
const char *ENERGY_DELIVERY_STOPPED = "energy-delivery-stopped";
const char *SESSION_STOPPED = "session-stopped";

const char *TOPIC_DELIMITER = "/";

const char *READ_TOPICS[] = {
    SESSION_INIT,
    SESSION_STOP,
    FUNCTION_PARAMS,
    PTMAX,
    REVERT_TO_DEFAULT,
    ENERGY_DELIVERY_START,
    ENERGY_DELIVERY_STOP,
    ELECTRICITY_DATA_INTERVAL,
    RELAY_TEST_ON, RELAY_TEST_OFF, RELAY_TEST_KICK};

const char *WRITE_TOPICS[] = {
    ELECTRICITY_DATA,
    POWER_EXCEEDED,
    ENERGY_DELIVERY_STOPPED,
    SESSION_STOPPED};

const int readTopicCount = sizeof(READ_TOPICS) / sizeof(READ_TOPICS[0]);

const char *CLIENT_NAME = "ESP32Client";
const int BUFFER_SIZE = 4096;

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
    Serial.println(MQTTClient::instance->actions.test1());
    // Forward the callback to the actual member function
    // MQTTClient::instance->callback(topic, payload, length);
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