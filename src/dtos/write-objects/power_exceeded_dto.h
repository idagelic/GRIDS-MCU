#ifndef POWER_EXCEEDED_DTO_H
#define POWER_EXCEEDED_DTO_H

class PowerExceededDTO
{
public:
    PowerExceededDTO();
    PowerExceededDTO(int session_id, int amount);

    int getSessionId();
    int getAmount();

private:
    int session_id;
    int amount;
};

#endif