///*
// * File:   touch.c
// * Author: Yobikid
// *
// * Created on May 30, 2019, 8:28 PM
// */
//#include <xc.h>
//#include "mcc_generated_files/mcc.h"
//#include "touch.h"
//#include "led.h"
//#include "stdio.h"
//union
//{
//    unsigned int full_status;
//    struct
//    {
//        unsigned DEBONCE :1;
//        unsigned BT_1    :1;
//        unsigned BT_2    :1;
//        unsigned BT_3    :1;
//        unsigned BT_1_ON_OFF :1;
//        unsigned BT_2_ON_OFF :1;
//        unsigned BT_3_ON_OFF :1;
//        unsigned BT_PRESSED :1;
//    };
//}bt_status;
//void myButtonPressedCallback(enum mtouch_button_names button)
//{
//    printf("The button %d is pressed.\r\n", button);
//    if(button == 0)// button2
//    {
//        bt_status.BT_2_ON_OFF = (~bt_status.BT_2_ON_OFF);
//        if(bt_status.BT_2_ON_OFF == 1)
//        {
//            LED_PROCESS(2,1,0);
//            bt_status.BT_2 = 0;
//        }
//        else
//        {
//            LED_PROCESS(2,0,1);
//            bt_status.BT_2 = 0;
//        }       
//    }
//    if(button == 1)// button3
//    {
//        bt_status.BT_3_ON_OFF = (~bt_status.BT_3_ON_OFF);
//        if(bt_status.BT_3_ON_OFF == 1)
//        {
//            LED_PROCESS(3,1,0);
//            bt_status.BT_3 = 0;
//        }
//        else
//        {
//            LED_PROCESS(3,0,1);
//            bt_status.BT_3 = 0;
//        } 
//    }
//    if(button == 2)// button1
//    {
//        bt_status.BT_1_ON_OFF = (~bt_status.BT_1_ON_OFF);
//        if(bt_status.BT_1_ON_OFF == 1)
//        {
//            LED_PROCESS(1,1,0);
//            bt_status.BT_1 = 0;
//        }
//        else
//        {
//            LED_PROCESS(1,0,1);
//            bt_status.BT_1 = 0;
//        } 
//    }
//}
// 
//void myButtonReleasedCallback(enum mtouch_button_names button)
//{
//    printf("The button %d is released.\r\n", button);
//}