#include "energy_message.h"

EnergyMessage::EnergyMessage(int counter, int sessionId, float kWhCumulativeEnergy, float wattAveragePower)
{
    this->counter = counter;
    this->sessionId = sessionId;
    this->kWhCumulativeEnergy = kWhCumulativeEnergy;
    this->wattAveragePower = wattAveragePower;
    this->createdAt = time(NULL);
}

int EnergyMessage::getCounter()
{
    return counter;
}

int EnergyMessage::getSessionId()
{
    return sessionId;
}

float EnergyMessage::getKWhCumulativeEnergy()
{
    return kWhCumulativeEnergy;
}

float EnergyMessage::getWattAveragePower()
{
    return wattAveragePower;
}

time_t EnergyMessage::getCreatedAt()
{
    return createdAt;
}