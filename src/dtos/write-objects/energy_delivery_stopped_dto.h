#ifndef ENERGY_DELIVERY_STOPPED_DTO_H
#define ENERGY_DELIVERY_STOPPED_DTO_H

class EnergyDeliveryStoppedDTO
{
public:
    EnergyDeliveryStoppedDTO();
    EnergyDeliveryStoppedDTO(int session_id, int reason_for_stop);

    int getSessionId();
    int getReasonForStop();

private:
    int session_id;
    int reason_for_stop;
};

#endif

const int ENERGY_DELIVERY_NO_INTERNET = 1;
const int ENERGY_DELIVERY_POWER_EXCEEDED = 2;