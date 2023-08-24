#ifndef DATA_H
#define DATA_H

// Manages configuration of board - UUID, SSID, MQTT broker URL etc.

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

class Data
{
public:
    Data();

    void setup();
    void loop();
    void checkSerialInput();
    String getConfigField(const char *fieldName);
    String getRootCA();
    bool checkDataReady();

private:
    const char *configFileName = "/config.txt";
    const int jsonCapacity = JSON_OBJECT_SIZE(3) + 90;

    void updateConfig(const char *newLine);
    String readConfig(const char *fieldName);
};

#endif
