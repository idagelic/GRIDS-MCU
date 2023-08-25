#ifndef MAIN_H
#define MAIN_H

#include "data.h"
// #include "internet.h"
#include "mqtt.h"
#include "domain.h"
#include "actions.h"

extern Data data;
extern MQTTClient mqtt;
extern Domain domain;
extern Actions actions;

void testFunctionalParameters();
void connectToMqtt();
void checkMqttConnection();

void setup();
void loop();

#endif // MAIN_H