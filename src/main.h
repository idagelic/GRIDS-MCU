#ifndef MAIN_H
#define MAIN_H

#include "data.h"
#include "internet.h"
#include "mqtt.h"

extern Data data;
extern MQTTClient mqtt;

void connectToMqtt();
void checkMqttConnection();

void setup();
void loop();

#endif // MAIN_H