#ifndef FUNCTIONAL_PARAMETERS_H
#define FUNCTIONAL_PARAMETERS_H

#include <time.h>

class FunctionalParameters
{
public:
    FunctionalParameters();
    FunctionalParameters(int pMaxActionThreshold, int pMaxActionDelay, int energyDeliveryStopDelay, int energyMessageInterval);

    int getPMaxActionThreshold();
    int getPMaxActionDelay();
    int getEnergyDeliveryStopDelay();
    int getEnergyMessageInterval();

private:
    int pMaxActionThreshold;
    int pMaxActionDelay;
    int energyDeliveryStopDelay;
    int energyMessageInterval;
};

#endif
