#include "mqtt.h"
// #include "domain.h"

const int TEST_RELAY_PIN_NUMBER = 13; // Replace with the desired pin number

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
    RELAY_TEST_ON, RELAY_TEST_OFF};

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

    if (strcmp(topic, strcat(uuidCharArray, RELAY_TEST_ON)) == 0)
    {
        Serial.println("Doslo on");
        digitalWrite(TEST_RELAY_PIN_NUMBER, HIGH); // Replace with real pin number
    }

    if (strcmp(topic, strcat(uuidCharArray, RELAY_TEST_OFF)) == 0)
    {
        Serial.println("Doslo off");
        digitalWrite(TEST_RELAY_PIN_NUMBER, LOW); // Replace with real pin number
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