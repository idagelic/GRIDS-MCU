#ifndef ACTIONS_H
#define ACTIONS_H

#include <WiFi.h>
#include <ArduinoJson.h>
#include "constants.h"

class Actions
{
public:
	Actions();
	static void processMessage(String uuid, char *topic, byte *payload, unsigned int length);
};

#endif
