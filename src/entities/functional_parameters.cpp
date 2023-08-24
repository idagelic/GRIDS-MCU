#include "functional_parameters.h"

FunctionalParameters::FunctionalParameters() {}

FunctionalParameters::FunctionalParameters(int pMaxActionThreshold, int pMaxActionDelay, int energyDeliveryStopDelay, int energyMessageInterval)
{
    this->pMaxActionThreshold = pMaxActionThreshold;
    this->pMaxActionDelay = pMaxActionDelay;
    this->energyDeliveryStopDelay = energyDeliveryStopDelay;
    this->energyMessageInterval = energyMessageInterval;
}

int FunctionalParameters::getPMaxActionThreshold()
{
    return pMaxActionThreshold;
}

int FunctionalParameters::getPMaxActionDelay()
{
    return pMaxActionDelay;
}

int FunctionalParameters::getEnergyDeliveryStopDelay()
{
    return energyDeliveryStopDelay;
}

int FunctionalParameters::getEnergyMessageInterval()
{
    return energyMessageInterval;
}