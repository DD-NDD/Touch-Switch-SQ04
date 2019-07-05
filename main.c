#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "led.h"
#include "relay.h"
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
    last_touch_status.full_status = last_touch_status.full_status ^ MTOUCH_Button_Buttonmask_Get();
    // update status to last_touch_status memory
    LED_PROCESS(last_touch_status.full_status);
    RELAY_PROCESS(last_touch_status.full_status);
}
void myButtonReleasedCallback(enum mtouch_button_names button)
{
}       