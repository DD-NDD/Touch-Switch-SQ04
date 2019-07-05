#include <stdbool.h>
#include <stdint.h>
/*Glass status*/
extern volatile bool config_status;
/*----------------------------------------------------------------------------*/
/* define status touch*/
bool busy_flag;
extern volatile bool check_request;
extern volatile bool rest;
bool dir_mes;
union
{
    unsigned int full_status;
    struct
    {
        unsigned DEBONCE :1;
        unsigned BT_1    :1;
        unsigned BT_2    :1;
        unsigned BT_3    :1;
        unsigned BT_1_ON_OFF :1;
        unsigned BT_2_ON_OFF :1;
        unsigned BT_3_ON_OFF :1;
        unsigned BT_PRESSED :1;
    };
}bt_status;
/*End define status touch*/