#ifndef MQTT_H
#define MQTT_H

#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "internet.h"
#include "actions.h"

class MQTTClient
{
public:
    MQTTClient() : client(espClient){};
    WiFiClientSecure espClient;
    PubSubClient client;
    String uuid;
    Actions actions;
    void initWifiConnection(const char *ssid, const char *password);
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