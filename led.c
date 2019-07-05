/*
 * File:   led.c
 * Author: Yobikid
 *
 * Created on May 30, 2019, 8:17 PM
 */
#include "led.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdbool.h>
void LED_PROCESS(uint8_t x)
{
    switch(x)
    {
        case 0:
        {
            LED_3_SetHigh();LED_2_SetHigh();LED_1_SetHigh();LED_0_SetHigh();
            break;
        }
        case 1:
        {
            LED_3_SetHigh();LED_2_SetHigh();LED_1_SetHigh();LED_0_SetLow();
            break;
        }
        case 2:
        {
            LED_3_SetHigh();LED_2_SetHigh();LED_1_SetLow();LED_0_SetHigh();
            break;
        }
        case 3:
        {
            LED_3_SetHigh();LED_2_SetHigh();LED_1_SetLow();LED_0_SetLow();
            break;
        }
        case 4:
        {
            LED_3_SetHigh();LED_2_SetLow();LED_1_SetHigh();LED_0_SetHigh();
            break;
        }
        case 5:
        {
            LED_3_SetHigh();LED_2_SetLow();LED_1_SetHigh();LED_0_SetLow();
            break;
        }
        case 6:
        {
            LED_3_SetHigh();LED_2_SetLow();LED_1_SetLow();LED_0_SetHigh();
            break;
        }
        case 7:
        {
            LED_3_SetHigh();LED_2_SetLow();LED_1_SetLow();LED_0_SetLow();
            break;
        }
        case 8:
        {
            LED_3_SetLow();LED_2_SetHigh();LED_1_SetHigh();LED_0_SetHigh();
            break;
        }
        case 9:
        {
            LED_3_SetLow();LED_2_SetHigh();LED_1_SetHigh();LED_0_SetLow();
            break;
        }
        case 10:
        {
            LED_3_SetLow();LED_2_SetHigh();LED_1_SetLow();LED_0_SetHigh();
            break;
        }
        case 11:
        {
            LED_3_SetLow();LED_2_SetHigh();LED_1_SetLow();LED_0_SetLow();
            break;
        }
        case 12:
        {
            LED_3_SetLow();LED_2_SetLow();LED_1_SetHigh();LED_0_SetHigh();
            break;
        }
        case 13:
        {
            LED_3_SetLow();LED_2_SetLow();LED_1_SetHigh();LED_0_SetLow();
            break;
        }
        case 14:
        {
            LED_3_SetLow();LED_2_SetLow();LED_1_SetLow();LED_0_SetHigh();
            break;
        }
        case 15:
        {
            LED_3_SetLow();LED_2_SetLow();LED_1_SetLow();LED_0_SetLow();
            break;
        }
    }
}