#ifndef MQTT_H
#define MQTT_H

#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char *SESSION_INIT = "/commands/session-init";
const char *SESSION_STOP = "/commands/session-stop";
const char *FUNCTION_PARAMS = "/commands/function-parameters";
const char *PTMAX = "/commands/ptmax";
const char *REVERT_TO_DEFAULT = "/commands/revert-to-default";
const char *ENERGY_DELIVERY_START = "/commands/energy-delivery-start";
const char *ENERGY_DELIVERY_STOP = "/commands/energy-delivery-stop";
const char *ELECTRICITY_DATA_INTERVAL = "/commands/electricity-data-interval";

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
    ELECTRICITY_DATA_INTERVAL};

const char *WRITE_TOPICS[] = {
    ELECTRICITY_DATA,
    POWER_EXCEEDED,
    ENERGY_DELIVERY_STOPPED,
    SESSION_STOPPED};

const int readTopicCount = sizeof(READ_TOPICS) / sizeof(READ_TOPICS[0]);

const char *CLIENT_NAME = "ESP32Client";
const int BUFFER_SIZE = 4096;

class MQTTClient
{
public:
    MQTTClient() : client(espClient){};
    WiFiClientSecure espClient;
    PubSubClient client;
    String uuid;
    void connect(const char *brokerUrl, int port, const char *username, const char *password, const char *certificate);
    static void staticCallback(char *topic, byte *payload, unsigned int length);
    void callback(char *topic, byte *payload, unsigned int length);
    void checkReconnect();
    void loop();
    void publish(const char *topic, const char *message);

private:
    static MQTTClient *instance;
    std::function<void(char *, uint8_t *, unsigned int)> callbackFunction;
};

#endif