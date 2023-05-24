#ifndef SESSION_STOPPED_DTO_H
#define SESSION_STOPPED_DTO_H

#include <time.h>

class SessionStoppedDTO
{
public:
    SessionStoppedDTO();
    SessionStoppedDTO(int session_id, int reason_for_stop, float kwh_energy_delivered, time_t created_at);

    int getSessionId();
    int getReasonForStop();
    float getKwhEnergyDelivered();
    time_t getCreatedAt();

private:
    int session_id;
    int reason_for_stop;
    float kwh_energy_delivered;
    time_t created_at;
};

#endif

const int SESSION_STOPPED_EXTERNAL_COMMAND = 0;
const int SESSION_STOPPED_TIME_ELAPSED = 1;
const int SESSION_STOPPED_ENERGY_EXCEEDED = 2;
