#ifndef SESSION_INIT_DTO_H
#define SESSION_INIT_DTO_H

#include <time.h>

class SessionInitDTO
{
public:
    int session_id;
    float kwh_contracted_energy;
    float watt_pmax;
    time_t ends_at;
};

#endif