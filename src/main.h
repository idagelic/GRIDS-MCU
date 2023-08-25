#ifndef MAIN_H
#define MAIN_H

#include "data.h"
// #include "internet.h"
// #include "mqtt.h"
// #include "domain.h"

extern Data data;
// extern MQTTClient mqtt;
// extern Domain domain;

void testFunctionalParameters();
void connectToMqtt();
void checkMqttConnection();

void setup();
void loop();

#endif // MAIN_H