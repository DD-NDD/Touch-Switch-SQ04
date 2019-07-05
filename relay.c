#include<xc.h>
#include<stdint.h>
#include"relay.h"
#include"mcc_generated_files/pin_manager.h"
void RELAY_PROCESS(uint8_t x)
{
    switch(x)
    {
        case 0:
        {
            RL3_SetHigh();RL2_SetHigh();RL1_SetHigh();RL0_SetHigh();
            break;
        }
        case 1:
        {
            RL3_SetHigh();RL2_SetHigh();RL1_SetHigh();RL0_SetLow();
            break;
        }
        case 2:
        {
            RL3_SetHigh();RL2_SetHigh();RL1_SetLow();RL0_SetHigh();
            break;
        }
        case 3:
        {
            RL3_SetHigh();RL2_SetHigh();RL1_SetLow();RL0_SetLow();
            break;
        }
        case 4:
        {
            RL3_SetHigh();RL2_SetLow();RL1_SetHigh();RL0_SetHigh();
            break;
        }
        case 5:
        {
            RL3_SetHigh();RL2_SetLow();RL1_SetHigh();RL0_SetLow();
            break;
        }
        case 6:
        {
            RL3_SetHigh();RL2_SetLow();RL1_SetLow();RL0_SetHigh();
            break;
        }
        case 7:
        {
            RL3_SetHigh();RL2_SetLow();RL1_SetLow();RL0_SetLow();
            break;
        }
        case 8:
        {
            RL3_SetLow();RL2_SetHigh();RL1_SetHigh();RL0_SetHigh();
            break;
        }
        case 9:
        {
            RL3_SetLow();RL2_SetHigh();RL1_SetHigh();RL0_SetLow();
            break;
        }
        case 10:
        {
            RL3_SetLow();RL2_SetHigh();RL1_SetLow();RL0_SetHigh();
            break;
        }
        case 11:
        {
            RL3_SetLow();RL2_SetHigh();RL1_SetLow();RL0_SetLow();
            break;
        }
        case 12:
        {
            RL3_SetLow();RL2_SetLow();RL1_SetHigh();RL0_SetHigh();
            break;
        }
        case 13:
        {
            RL3_SetLow();RL2_SetLow();RL1_SetHigh();RL0_SetLow();
            break;
        }
        case 14:
        {
            RL3_SetLow();RL2_SetLow();RL1_SetLow();RL0_SetHigh();
            break;
        }
        case 15:
        {
            RL3_SetLow();RL2_SetLow();RL1_SetLow();RL0_SetLow();
            break;
        }
    }    
}
