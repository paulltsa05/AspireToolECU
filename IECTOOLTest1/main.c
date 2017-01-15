/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F18344
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

#include "mcc_generated_files/mcc.h"
#include "main.h"
#include "Buzzer_Ctrl.h"
#include "LED_Ctrl.h"
#include "Fan_Ctrl.h"
#include "CommunicationManager.h"



unsigned int Msec_cnt=0,Msec10_cnt=0,DelayMsecCount=0;

char byteIN[10],i,txRS485flag=0;
unsigned int ToolTemp_adc=0;

void One_msec_task(void);
void One_sec_task(void);
/*
                         Main application
 */
void interrupt INTERRUPT_InterruptManager();

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    BuzzerStartConfig(1,10);//(unsigned char BuzzDurationSec, unsigned char BuzzNumBeep);
    //char LedONStartConfig(unsigned char LEDcolor, unsigned char LedONDurationSec, unsigned char LedONNumBlink)
    LedONStartConfig(LED_RED, 4, 10);
    while(LedONStatusBusy());//wait for LED blink 
    
    //char FanStartConfig(unsigned char FanONDurationSec)
    FanStartConfig(2);
    BuzzerStartConfig(4,10);
    LedONStartConfig(LED_GREEN, 4, 10);
    while(LedONStatusBusy());//wait for LED blink 

    BuzzerStartConfig(1,10);
    LedONStartConfig(LED_BLUE, 4, 10);
    while(LedONStatusBusy());//wait for LED blink
    
    FanStartConfig(2);
    
    RS422_TXEN_RB6_SetLow(); // ensure TX on RS485 is disabled.
 //   RS422_TXEN_RB6_SetHigh();
    while(1)
    {
       ProtocolManager();
    //    for(i=0;i<10;i++)
    //    {
    //        byteIN[i]= ~EUSART_Read();
    //        if(i==9)
    //            i=0;
     //   }
//        if(Msec10_cnt>5000)
//        {
//           Msec10_cnt=0;
//           RS422_TXEN_RB6_SetHigh();
//           EUSART_RX_Disable();
//           //PIR1bits.TXIF=1;
//           EUSART_Write('A');
//           //RS422_TXEN_RB6_SetLow();
//           EUSART_Write('B');
//           EUSART_Write('C');
//           EUSART_Write('\n');
//           EUSART_Write('\r');
//           EUSART_Write(0x00);
//           //EUSART_Write(0xAA);
//           EUSART_TX_Completed();
//           RS422_TXEN_RB6_SetLow();
//           EUSART_RX_Enable();
//        }
    }
}

void One_msec_task(void)
{
    Buzzer_Control_msec();
    LedON_Control_msec();
    DelayMsecCount++;  
    Msec10_cnt++;
    if(Msec_cnt++ == 1000)
    {
        Msec_cnt=0;
        One_sec_task();
        
    }

}

void One_sec_task(void)
{
    Fan_Control_Sec();
    
}





/**
 End of File
*/