#include "domain.h"

Domain::Domain() {}

FunctionalParameters Domain::getFunctionalParameters()
{
    return functionalParameters;
}

void Domain::processFunctionParams(DynamicJsonDocument jsonDoc)
{
    if (jsonDoc.containsKey("pMaxActionThreshold") &&
        jsonDoc.containsKey("pMaxActionDelay") &&
        jsonDoc.containsKey("energyDeliveryStopDelay") &&
        jsonDoc.containsKey("energyMessageInterval"))
    {

        int pMaxActionThreshold = jsonDoc["pMaxActionThreshold"];
        int pMaxActionDelay = jsonDoc["pMaxActionDelay"];
        int energyDeliveryStopDelay = jsonDoc["energyDeliveryStopDelay"];
        int energyMessageInterval = jsonDoc["energyMessageInterval"];

        functionalParameters = FunctionalParameters(
            pMaxActionThreshold,
            pMaxActionDelay,
            energyDeliveryStopDelay,
            energyMessageInterval);
    }
}

void Domain::processSessionInit(DynamicJsonDocument data)
{
    if (!data.containsKey("") || !data.containsKey(""))
    {
        return;
    }
}