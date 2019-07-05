#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "led.h"
#include "define.h"
// aaaaa
/*
                         Main application
 */
uint16_t count_conf = 0;
/*Call Back-------------------------------------------------------------------*/
void myButtonPressedCallback(enum mtouch_button_names button);
void myButtonReleasedCallback(enum mtouch_button_names button);
/*----------------------------------------------------------------------------*/
void PROCESS_RELAY(bool relay_1,bool relay_2,bool relay_3)
{
    if(relay_1)
    {
        RL1_SetLow();
    }
    else
    {
        RL1_SetHigh();
    }
    
    if(relay_2)
    {
        RL2_SetLow();
    }
    else
    {
        RL2_SetHigh();
    }
    
    if(relay_3)
    {
        RL3_SetLow();
    }
    else
    {
        RL3_SetHigh();
    }
}
/*----------------------------------------------------------------------------*/
uint8_t update_state();
void DATA_PROCESS(char x);
void check_message(uint8_t x)
{
    switch (x)
    {
        case 'T': 
        {
            check_request = false;
            break;
        }
        case 'F': 
        {
            check_request = false;
            break;
        }
        default:
        {
            printf("%c",x);            
            check_request = true;
            break;
        }
    }
}
bool  check_data(uint8_t x)
{
    switch(x)
    {
        case '0': return true;
        case '1': return true;
        case '2': return true;
        case '3': return true;
        case '4': return true;
        case '5': return true;
        case '6': return true;
        case '7': return true;
        case 'T': return true;
        case 'F': return true;
        case 'U': return true;
        default : return false;
    }
}
void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    INTCONbits.TMR0IE = 0;
    INTCONbits.TMR0IF = 0;
    rest = false;
    busy_flag = false;
    bt_status.full_status = 0;
    LED_EN();
    LED_PROCESS(1,0,1);
    LED_PROCESS(2,0,1);
    LED_PROCESS(3,0,1);
    RL1_SetHigh();
    RL2_SetHigh();
    RL3_SetHigh();
    MTOUCH_Button_SetPressedCallback(myButtonPressedCallback);
    MTOUCH_Button_SetNotPressedCallback(myButtonReleasedCallback);
    volatile uint8_t rxData;
    volatile uint8_t prcData;
    check_request = false;
    config_status = false;
    bool blink;
    uint8_t blink_count = 0;
    while (1)
    {
        
        if(rest == true)
        {
            if(bt_status.BT_1_ON_OFF == 1)
            {
                LED_PROCESS(1,1,0);
            }
            else
            {
                LED_PROCESS(1,0,1);
            }
            if(bt_status.BT_2_ON_OFF == 1)
            {
                LED_PROCESS(2,1,0);
            }
            else
            {
                LED_PROCESS(2,0,1);
            }
            if(bt_status.BT_3_ON_OFF == 1)
            {
                LED_PROCESS(3,1,0);
            }
            else
            {
                LED_PROCESS(3,0,1);
            }
            rest = false;
            MTOUCH_Initialize();
        }
        if(EUSART_is_rx_ready())
        {
            rxData = EUSART_Read();
            if(check_data(rxData))
            {
                if(check_request == false)// khong co gi de check
                {
                    prcData = rxData;
                    check_message(rxData);                  
                }
                else// da gui lenh check, xac nhan
                {
                    if(config_status == true)
                    {
                        if(rxData == 'T')
                        {
                            LED_PROCESS(1,1,0);  
                            LED_PROCESS(2,1,0);
                            LED_PROCESS(3,1,0);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            config_status = false;
                            rest = true;
                        }
                        if(rxData == 'F')
                        {            
                            LED_PROCESS(1,0,1);
                            LED_PROCESS(2,0,1);
                            LED_PROCESS(3,0,1);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            __delay_ms(500);
                            config_status = false;
                            rest = true;
                        }
                        
                    }
                    else
                    {
                        if(rxData == 'T')
                        {
                            DATA_PROCESS(prcData);
                        }
                        if(rxData == 'F')
                        {                        
                            check_request = false;// xoa request
                        }
                    }
                }
            }
        }
        if(MTOUCH_Service_Mainloop())
        {
            if(config_status == 0)
            {               
                if(MTOUCH_Button_isPressed(1) == 1 &&
                        MTOUCH_Button_isPressed(0) == 0 &&
                        MTOUCH_Button_isPressed(2) == 0)
                {
                    
                    count_conf++;
                    if(count_conf == 1500)
                    {         
                        count_conf = 0;
                        printf("PICSMART");
                        config_status = true;
                        check_request = true;
                        LED_PROCESS(2,0,1);
                        LED_PROCESS(1,0,1);
                        LED_PROCESS(3,0,1);
                        blink = false;
                    }
                }
                else
                {
                    count_conf = 0;
                }
            }
            else
            {
                blink_count++;
                if(blink == false)
                {
                    LED_PROCESS(1,0,1);
                    LED_PROCESS(2,0,1);
                    LED_PROCESS(3,0,1);
                    if(blink_count == 200)
                    {
                        blink_count = 0;
                        blink = true;
                    }                                      
                }
                else
                {
                    LED_PROCESS(1,1,0);
                    LED_PROCESS(2,1,0);
                    LED_PROCESS(3,1,0);
                    if(blink_count == 200)
                    {
                        blink_count = 0;
                        blink = false;
                    } 
                }  
            }
        }
    }
}
/* Call Back -----------------------------------------------------------------*/
void myButtonPressedCallback(enum mtouch_button_names button)
{
    if(config_status == false)
    {
        count_conf = 0;
        if(button == 0)
        {
            bt_status.BT_3_ON_OFF = (~bt_status.BT_3_ON_OFF);
            if(bt_status.BT_3_ON_OFF == 1)
            {
                LED_PROCESS(3,1,0);
                bt_status.BT_3 = 1;
            }
            else
            {
                LED_PROCESS(3,0,1);
                bt_status.BT_3  = 0;
            }       
        }
        if(button == 1)
        {
            bt_status.BT_2_ON_OFF = (~bt_status.BT_2_ON_OFF);
            if(bt_status.BT_2_ON_OFF == 1)
            {
                LED_PROCESS(2,1,0);
                bt_status.BT_2 = 1;
            }
            else
            {
                LED_PROCESS(2,0,1);
                bt_status.BT_2 = 0;
            } 
        }
        if(button == 2)
        {
            bt_status.BT_1_ON_OFF = (~bt_status.BT_1_ON_OFF);
            if(bt_status.BT_1_ON_OFF == 1)
            {
                LED_PROCESS(1,1,0);
                bt_status.BT_1 = 1;
            }
            else
            {
                LED_PROCESS(1,0,1);
                bt_status.BT_1 = 0;
            } 
        } 
        PROCESS_RELAY(bt_status.BT_1,bt_status.BT_2,bt_status.BT_3);
    }
}
uint8_t update_state(void)
{
    
    bt_status.BT_1 = bt_status.BT_1_ON_OFF;
    bt_status.BT_2 = bt_status.BT_2_ON_OFF;
    bt_status.BT_3 = bt_status.BT_3_ON_OFF;
    
    uint8_t state;
    if(bt_status.BT_1==0&&bt_status.BT_2==0&&bt_status.BT_3==0) state = 0;
    if(bt_status.BT_1==0&&bt_status.BT_2==0&&bt_status.BT_3==1) state = 1;
    if(bt_status.BT_1==0&&bt_status.BT_2==1&&bt_status.BT_3==0) state = 2;
    if(bt_status.BT_1==0&&bt_status.BT_2==1&&bt_status.BT_3==1) state = 3;
    if(bt_status.BT_1==1&&bt_status.BT_2==0&&bt_status.BT_3==0) state = 4;
    if(bt_status.BT_1==1&&bt_status.BT_2==0&&bt_status.BT_3==1) state = 5;
    if(bt_status.BT_1==1&&bt_status.BT_2==1&&bt_status.BT_3==0) state = 6;
    if(bt_status.BT_1==1&&bt_status.BT_2==1&&bt_status.BT_3==1) state = 7 ;
    return state;
}
void myButtonReleasedCallback(enum mtouch_button_names button)
{
    /* khi cac nut deu duoc released thi cap nhat trang thai*/
    if(config_status == false)
    {
        if(MTOUCH_Button_isPressed(0)==0&&MTOUCH_Button_isPressed(1)==0&&MTOUCH_Button_isPressed(2)==0)
        {
            printf("PIC%d",update_state());      
        }
    }
}       
/*----------------------------------------------------------------------------*/
/* Data Process -----------------------------------------------------------------*/
void DATA_PROCESS(char x)
{
    switch(x)
    {
        case '0':
        {
            LED_PROCESS(1,0,1); bt_status.BT_1_ON_OFF = 0;
            LED_PROCESS(2,0,1); bt_status.BT_2_ON_OFF = 0;
            LED_PROCESS(3,0,1); bt_status.BT_3_ON_OFF = 0;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case '1':
        {
            LED_PROCESS(1,0,1); bt_status.BT_1_ON_OFF = 0;
            LED_PROCESS(2,0,1); bt_status.BT_2_ON_OFF = 0;
            LED_PROCESS(3,1,0); bt_status.BT_3_ON_OFF = 1;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case '2':
        {
            LED_PROCESS(1,0,1); bt_status.BT_1_ON_OFF = 0;
            LED_PROCESS(2,1,0); bt_status.BT_2_ON_OFF = 1;
            LED_PROCESS(3,0,1); bt_status.BT_3_ON_OFF = 0;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case '3':
        {
            LED_PROCESS(1,0,1); bt_status.BT_1_ON_OFF = 0;
            LED_PROCESS(2,1,0); bt_status.BT_2_ON_OFF = 1;
            LED_PROCESS(3,1,0); bt_status.BT_3_ON_OFF = 1;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case '4':
        {
            LED_PROCESS(1,1,0); bt_status.BT_1_ON_OFF = 1;
            LED_PROCESS(2,0,1); bt_status.BT_2_ON_OFF = 0;
            LED_PROCESS(3,0,1); bt_status.BT_3_ON_OFF = 0;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case '5':
        {
            LED_PROCESS(1,1,0); bt_status.BT_1_ON_OFF = 1;
            LED_PROCESS(2,0,1); bt_status.BT_2_ON_OFF = 0;
            LED_PROCESS(3,1,0); bt_status.BT_3_ON_OFF = 1;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case '6':
        {
            LED_PROCESS(1,1,0); bt_status.BT_1_ON_OFF = 1;
            LED_PROCESS(2,1,0); bt_status.BT_2_ON_OFF = 1;
            LED_PROCESS(3,0,1); bt_status.BT_3_ON_OFF = 0;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case '7':
        {
            LED_PROCESS(1,1,0); bt_status.BT_1_ON_OFF = 1;
            LED_PROCESS(2,1,0); bt_status.BT_2_ON_OFF = 1;
            LED_PROCESS(3,1,0); bt_status.BT_3_ON_OFF = 1;
            PROCESS_RELAY(bt_status.BT_1_ON_OFF,bt_status.BT_2_ON_OFF,bt_status.BT_3_ON_OFF);
            check_request = false;
            break;
        }
        case 'U':
        {
            printf("PIC%d",update_state());
            break;
        }
        default:
        {
            check_request = false;
            break;
        }
    }
}