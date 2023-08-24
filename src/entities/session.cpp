#include "session.h"

Session::Session() {}

Session::Session(int id, int pMax, int tPMax, int tPMaxTimeout, bool energyDeliveryStatus, float kWhCumulativeEnergy, int energyMessageInterval)
{
    this->id = id;
    this->pMax = pMax;
    this->tPMax = tPMax;
    this->tPMaxTimeout = tPMaxTimeout;
    this->energyDeliveryStatus = energyDeliveryStatus;
    this->kWhCumulativeEnergy = kWhCumulativeEnergy;
    this->energyMessageInterval = energyMessageInterval;
}

int Session::getId()
{
    return id;
}

int Session::getPMax()
{
    return pMax;
}

int Session::getTPMax()
{
    return tPMax;
}

int Session::getTPMaxTimeout()
{
    return tPMaxTimeout;
}

bool Session::getEnergyDeliveryStatus()
{
    return energyDeliveryStatus;
}

float Session::getKWhCumulativeEnergy()
{
    return kWhCumulativeEnergy;
}

int Session::getEnergyMessageInterval()
{
    return energyMessageInterval;
}