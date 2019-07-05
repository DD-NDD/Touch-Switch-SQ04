#include <stdbool.h>
#include <stdint.h>
/*Glass status*/
union
{
    unsigned int full_status;
    struct
    {
        unsigned CS0    :1;
        unsigned CS1    :1;
        unsigned CS2    :1;
        unsigned CS3    :1;
        unsigned CS4    :1;
        unsigned CS5    :1;
        unsigned CS6    :1;
        unsigned CS7    :1;
    };
}last_touch_status;
/*End define status touch*/