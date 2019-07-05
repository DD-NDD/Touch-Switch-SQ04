#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "led.h"
#include "define.h"
/*
                         Main application
 */
uint16_t count_conf = 0;
void myButtonPressedCallback(enum mtouch_button_names button);
void myButtonReleasedCallback(enum mtouch_button_names button);
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    MTOUCH_Button_SetPressedCallback(myButtonPressedCallback);
    MTOUCH_Button_SetNotPressedCallback(myButtonReleasedCallback);
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
}
void myButtonReleasedCallback(enum mtouch_button_names button)
{
}       