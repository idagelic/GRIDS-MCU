#ifndef CONSTANTS_H
#define CONSTANTS_H

const char *SESSION_INIT = "/commands/session-init";
const char *SESSION_STOP = "/commands/session-stop";
const char *FUNCTION_PARAMS = "/commands/function-parameters";
const char *PTMAX = "/commands/ptmax";
const char *REVERT_TO_DEFAULT = "/commands/revert-to-default";
const char *ENERGY_DELIVERY_START = "/commands/energy-delivery-start";
const char *ENERGY_DELIVERY_STOP = "/commands/energy-delivery-stop";
const char *ELECTRICITY_DATA_INTERVAL = "/commands/electricity-data-interval";
const char *RELAY_TEST_ON = "/commands/relay-test-on";
const char *RELAY_TEST_OFF = "/commands/relay-test-off";
const char *RELAY_TEST_KICK = "/commands/relay-test-kick";

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
	ELECTRICITY_DATA_INTERVAL,
	RELAY_TEST_ON, RELAY_TEST_OFF, RELAY_TEST_KICK};

const char *WRITE_TOPICS[] = {
	ELECTRICITY_DATA,
	POWER_EXCEEDED,
	ENERGY_DELIVERY_STOPPED,
	SESSION_STOPPED};

const char *CLIENT_NAME = "ESP32Client";

#endif // CONSTANTS_H