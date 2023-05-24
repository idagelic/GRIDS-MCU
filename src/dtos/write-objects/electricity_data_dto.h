#ifndef ELECTRICITY_DATA_DTO_H
#define ELECTRICITY_DATA_DTO_H

#include <time.h>

class ElectricityDataDTO
{
public:
    ElectricityDataDTO();
    ElectricityDataDTO(int counter, int session_id, float kwh_cumulative_energy, float watt_average_power, time_t created_at);

    int getCounter();
    int getSessionId();
    float getKwhCumulativeEnergy();
    float getWattAveragePower();
    time_t getCreatedAt();

private:
    int counter;
    int session_id;
    float kwh_cumulative_energy;
    float watt_average_power;
    time_t created_at;
};

#endif