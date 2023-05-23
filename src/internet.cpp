#include "internet.h"

void connectToWiFi(const char *ssid, const char *password)
{
    Serial.print("Connecting to Wi-Fi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }

    Serial.println();
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());
}

void checkWifiConnection(const char *ssid, const char *password)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Connection lost. Reconnecting...");
        connectToWiFi(ssid, password);
    }
}
