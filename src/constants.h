#ifndef CONSTANTS_H
#define CONSTANTS_H

const int PIN_REL1 = 2; // Replace with the desired pin number
const int PIN_REL2 = 4; // Replace with the desired pin number

extern const char *SESSION_INIT;
extern const char *SESSION_STOP;
extern const char *FUNCTION_PARAMS;
extern const char *PTMAX;
extern const char *REVERT_TO_DEFAULT;
extern const char *ENERGY_DELIVERY_START;
extern const char *ENERGY_DELIVERY_STOP;
extern const char *ELECTRICITY_DATA_INTERVAL;
extern const char *RELAY_TEST_ON;
extern const char *RELAY_TEST_OFF;
extern const char *RELAY_TEST_KICK;

extern const char *ELECTRICITY_DATA;
extern const char *POWER_EXCEEDED;
extern const char *ENERGY_DELIVERY_STOPPED;
extern const char *SESSION_STOPPED;

extern const char *TOPIC_DELIMITER;

extern const char *READ_TOPICS[];

extern const char *WRITE_TOPICS[];

const int BUFFER_SIZE = 4096;

extern const char *CLIENT_NAME;

#endif // CONSTANTS_H