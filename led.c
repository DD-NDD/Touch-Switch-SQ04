/*
 * File:   led.c
 * Author: Yobikid
 *
 * Created on May 30, 2019, 8:17 PM
 */
#include "led.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdbool.h>
void LED_EN()
{
    LED_ALL_SetLow();
}
void LED_PROCESS(uint8_t led_name,bool blue,bool red)
{
    switch(led_name)
    {
        case 1:
        {
            if(blue) LED_B_1_SetLow();
            else LED_B_1_SetHigh();
            if(red) LED_R_1_SetLow();
            else LED_R_1_SetHigh();
            break;
        }
        case 2:
        {
            if(blue) LED_B_2_SetLow();
            else LED_B_2_SetHigh();
            if(red) LED_R_2_SetLow();
            else LED_R_2_SetHigh();
            break;
        }
        case 3:
        {
            if(blue) LED_B_3_SetLow();
            else LED_B_3_SetHigh();
            if(red) LED_R_3_SetLow();
            else LED_R_3_SetHigh();
            break;
        }
        default:
        {
            break;
        }
    }
}
