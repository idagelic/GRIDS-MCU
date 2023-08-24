#ifndef DOMAIN_H
#define DOMAIN_H

#include <ArduinoJson.h>
#include "entities/session.h"
#include "entities/functional_parameters.h"
#include "entities/energy_message.h"

#define SESSION_STOPPED_EXTERNAL_COMMAND 0
#define SESSION_STOPPED_TIME_ELAPSED 1
#define SESSION_STOPPED_ENERGY_EXCEEDED 2

#define ENERGY_DELIVERY_NO_INTERNET 1
#define ENERGY_DELIVERY_POWER_EXCEEDED 2

class Domain
{
public:
    Domain();

    FunctionalParameters getFunctionalParameters();

    void processSessionInit(DynamicJsonDocument);
    void processSessionStop(DynamicJsonDocument);
    void processFunctionParams(DynamicJsonDocument);
    void processPTMax(DynamicJsonDocument);
    void processRevertToDefault(DynamicJsonDocument);
    void processEnergyDeliveryStart(DynamicJsonDocument);
    void processEnergyDeliveryStop(DynamicJsonDocument);
    void processElectricityDataInterval(DynamicJsonDocument);

    void sendElectricityData(DynamicJsonDocument);
    void sendPowerExceeded(DynamicJsonDocument);
    void sendEnergyDeliveryStopped(DynamicJsonDocument);
    void sendSessionStopped(DynamicJsonDocument);

private:
    EnergyMessage *energyMessageList;
    Session session;
    FunctionalParameters functionalParameters;
};

#endif
