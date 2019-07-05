#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "led.h"
#include "define.h"
/*
                         Main application
 */
void myButtonPressedCallback(enum mtouch_button_names button);
void myButtonReleasedCallback(enum mtouch_button_names button);
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    MTOUCH_Button_SetPressedCallback(myButtonPressedCallback);
    MTOUCH_Button_SetNotPressedCallback(myButtonReleasedCallback);
    
    LED_EN_SetLow();
    while (1)
    {
        if(MTOUCH_Service_Mainloop())
        {            
        }
    }
}
/* Call Back -----------------------------------------------------------------*/
void myButtonPressedCallback(enum mtouch_button_names button)
{
    if(button == 0)
    {
        LED_0_Toggle();
    }
    if(button == 1)
    {
        LED_1_Toggle();
    }
    if(button == 2)
    {
        LED_2_Toggle();
    }
    if(button == 3)
    {
        LED_3_Toggle();
    }
}
void myButtonReleasedCallback(enum mtouch_button_names button)
{
}       