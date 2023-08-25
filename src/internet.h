#ifndef WIFI_H
#define WIFI_H

#include <WiFi.h>

void connectToWifi(const char *ssid, const char *password);
void checkWifiConnection(const char *ssid, const char *password);

#endif
