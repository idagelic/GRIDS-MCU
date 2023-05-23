#ifndef ENERGY_MESSAGE_H
#define ENERGY_MESSAGE_H

#include <time.h>

class EnergyMessage
{
public:
    EnergyMessage();
    EnergyMessage(int counter, int sessionId, float kWhCumulativeEnergy, float wattAveragePower);

    int getCounter();
    int getSessionId();
    float getKWhCumulativeEnergy();
    float getWattAveragePower();
    time_t getCreatedAt();

private:
    int counter;
    int sessionId;
    float kWhCumulativeEnergy;
    float wattAveragePower;
    time_t createdAt;
};

#endif
