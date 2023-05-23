#ifndef SESSION_H
#define SESSION_H

#include <time.h>

class Session
{
public:
    Session();
    Session(int id, int pMax, int tPMax, int tPMaxTimeout, bool energyDeliveryStatus, float kWhCumulativeEnergy, int energyMessageInterval);

    int getId();
    int getPMax();
    int getTPMax();
    int getTPMaxTimeout();
    bool getEnergyDeliveryStatus();
    float getKWhCumulativeEnergy();
    int getEnergyMessageInterval();

private:
    int id;
    int pMax;
    int tPMax;
    int tPMaxTimeout;
    bool energyDeliveryStatus;
    float kWhCumulativeEnergy;
    int energyMessageInterval;
};

#endif
