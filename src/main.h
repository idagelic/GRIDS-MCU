#ifndef MAIN_H
#define MAIN_H

#include "data.h"
#include "mqtt.h"
#include "actions.h"

extern Data data;
extern MQTTClient mqtt;
extern Actions actions;

void testFunctionalParameters();
void connectToMqtt();
void checkMqttConnection();

void setup();
void loop();

#endif // MAIN_H