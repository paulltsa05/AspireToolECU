/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F18344
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20

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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ANA_EXTRA_J2_2_RA5 aliases
#define ANA_EXTRA_J2_2_RA5_TRIS               TRISA5
#define ANA_EXTRA_J2_2_RA5_LAT                LATA5
#define ANA_EXTRA_J2_2_RA5_PORT               RA5
#define ANA_EXTRA_J2_2_RA5_WPU                WPUA5
#define ANA_EXTRA_J2_2_RA5_ANS                ANSA5
#define ANA_EXTRA_J2_2_RA5_SetHigh()    do { LATA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetLow()   do { LATA5 = 0; } while(0)
#define ANA_EXTRA_J2_2_RA5_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define ANA_EXTRA_J2_2_RA5_GetValue()         RA5
#define ANA_EXTRA_J2_2_RA5_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define ANA_EXTRA_J2_2_RA5_SetPullup()    do { WPUA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_ResetPullup()   do { WPUA5 = 0; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetDigitalMode()   do { ANSA5 = 0; } while(0)


// get/set ANA_EXTRA_J2_2_RA5 aliases
#define ANA_EXTRA_J2_2_RA5_TRIS               TRISA5
#define ANA_EXTRA_J2_2_RA5_LAT                LATA5
#define ANA_EXTRA_J2_2_RA5_PORT               RA5
#define ANA_EXTRA_J2_2_RA5_WPU                WPUA5
#define ANA_EXTRA_J2_2_RA5_ANS                ANSA5
#define ANA_EXTRA_J2_2_RA5_SetHigh()    do { LATA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetLow()   do { LATA5 = 0; } while(0)
#define ANA_EXTRA_J2_2_RA5_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define ANA_EXTRA_J2_2_RA5_GetValue()         RA5
#define ANA_EXTRA_J2_2_RA5_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define ANA_EXTRA_J2_2_RA5_SetPullup()    do { WPUA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_ResetPullup()   do { WPUA5 = 0; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetDigitalMode()   do { ANSA5 = 0; } while(0)


// get/set ANA_EXTRA_J2_2_RA5 aliases
#define ANA_EXTRA_J2_2_RA5_TRIS               TRISA5
#define ANA_EXTRA_J2_2_RA5_LAT                LATA5
#define ANA_EXTRA_J2_2_RA5_PORT               RA5
#define ANA_EXTRA_J2_2_RA5_WPU                WPUA5
#define ANA_EXTRA_J2_2_RA5_ANS                ANSA5
#define ANA_EXTRA_J2_2_RA5_SetHigh()    do { LATA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetLow()   do { LATA5 = 0; } while(0)
#define ANA_EXTRA_J2_2_RA5_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define ANA_EXTRA_J2_2_RA5_GetValue()         RA5
#define ANA_EXTRA_J2_2_RA5_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define ANA_EXTRA_J2_2_RA5_SetPullup()    do { WPUA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_ResetPullup()   do { WPUA5 = 0; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define ANA_EXTRA_J2_2_RA5_SetDigitalMode()   do { ANSA5 = 0; } while(0)


// get/set RS422_TXEN_RB6 aliases
#define RS422_TXEN_RB6_TRIS               TRISB6
#define RS422_TXEN_RB6_LAT                LATB6
#define RS422_TXEN_RB6_PORT               RB6
#define RS422_TXEN_RB6_WPU                WPUB6
#define RS422_TXEN_RB6_ANS                ANSB6
#define RS422_TXEN_RB6_SetHigh()    do { LATB6 = 1; } while(0)
#define RS422_TXEN_RB6_SetLow()   do { LATB6 = 0; } while(0)
#define RS422_TXEN_RB6_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define RS422_TXEN_RB6_GetValue()         RB6
#define RS422_TXEN_RB6_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define RS422_TXEN_RB6_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define RS422_TXEN_RB6_SetPullup()    do { WPUB6 = 1; } while(0)
#define RS422_TXEN_RB6_ResetPullup()   do { WPUB6 = 0; } while(0)
#define RS422_TXEN_RB6_SetAnalogMode()   do { ANSB6 = 1; } while(0)
#define RS422_TXEN_RB6_SetDigitalMode()   do { ANSB6 = 0; } while(0)


// get/set GPIO_J2_1_RB7 aliases
#define GPIO_J2_1_RB7_TRIS               TRISB7
#define GPIO_J2_1_RB7_LAT                LATB7
#define GPIO_J2_1_RB7_PORT               RB7
#define GPIO_J2_1_RB7_WPU                WPUB7
#define GPIO_J2_1_RB7_ANS                ANSB7
#define GPIO_J2_1_RB7_SetHigh()    do { LATB7 = 1; } while(0)
#define GPIO_J2_1_RB7_SetLow()   do { LATB7 = 0; } while(0)
#define GPIO_J2_1_RB7_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define GPIO_J2_1_RB7_GetValue()         RB7
#define GPIO_J2_1_RB7_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define GPIO_J2_1_RB7_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define GPIO_J2_1_RB7_SetPullup()    do { WPUB7 = 1; } while(0)
#define GPIO_J2_1_RB7_ResetPullup()   do { WPUB7 = 0; } while(0)
#define GPIO_J2_1_RB7_SetAnalogMode()   do { ANSB7 = 1; } while(0)
#define GPIO_J2_1_RB7_SetDigitalMode()   do { ANSB7 = 0; } while(0)


// get/set LED_RED_RC0 aliases
#define LED_RED_RC0_TRIS               TRISC0
#define LED_RED_RC0_LAT                LATC0
#define LED_RED_RC0_PORT               RC0
#define LED_RED_RC0_WPU                WPUC0
#define LED_RED_RC0_ANS                ANSC0
#define LED_RED_RC0_SetHigh()    do { LATC0 = 1; } while(0)
#define LED_RED_RC0_SetLow()   do { LATC0 = 0; } while(0)
#define LED_RED_RC0_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define LED_RED_RC0_GetValue()         RC0
#define LED_RED_RC0_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define LED_RED_RC0_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

#define LED_RED_RC0_SetPullup()    do { WPUC0 = 1; } while(0)
#define LED_RED_RC0_ResetPullup()   do { WPUC0 = 0; } while(0)
#define LED_RED_RC0_SetAnalogMode()   do { ANSC0 = 1; } while(0)
#define LED_RED_RC0_SetDigitalMode()   do { ANSC0 = 0; } while(0)


// get/set LED_GREEN_RC1 aliases
#define LED_GREEN_RC1_TRIS               TRISC1
#define LED_GREEN_RC1_LAT                LATC1
#define LED_GREEN_RC1_PORT               RC1
#define LED_GREEN_RC1_WPU                WPUC1
#define LED_GREEN_RC1_ANS                ANSC1
#define LED_GREEN_RC1_SetHigh()    do { LATC1 = 1; } while(0)
#define LED_GREEN_RC1_SetLow()   do { LATC1 = 0; } while(0)
#define LED_GREEN_RC1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define LED_GREEN_RC1_GetValue()         RC1
#define LED_GREEN_RC1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define LED_GREEN_RC1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

#define LED_GREEN_RC1_SetPullup()    do { WPUC1 = 1; } while(0)
#define LED_GREEN_RC1_ResetPullup()   do { WPUC1 = 0; } while(0)
#define LED_GREEN_RC1_SetAnalogMode()   do { ANSC1 = 1; } while(0)
#define LED_GREEN_RC1_SetDigitalMode()   do { ANSC1 = 0; } while(0)


// get/set LED_BLUE_RC2 aliases
#define LED_BLUE_RC2_TRIS               TRISC2
#define LED_BLUE_RC2_LAT                LATC2
#define LED_BLUE_RC2_PORT               RC2
#define LED_BLUE_RC2_WPU                WPUC2
#define LED_BLUE_RC2_ANS                ANSC2
#define LED_BLUE_RC2_SetHigh()    do { LATC2 = 1; } while(0)
#define LED_BLUE_RC2_SetLow()   do { LATC2 = 0; } while(0)
#define LED_BLUE_RC2_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED_BLUE_RC2_GetValue()         RC2
#define LED_BLUE_RC2_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define LED_BLUE_RC2_SetPullup()    do { WPUC2 = 1; } while(0)
#define LED_BLUE_RC2_ResetPullup()   do { WPUC2 = 0; } while(0)
#define LED_BLUE_RC2_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set LED_BLUE_RC2 aliases
#define LED_BLUE_RC2_TRIS               TRISC2
#define LED_BLUE_RC2_LAT                LATC2
#define LED_BLUE_RC2_PORT               RC2
#define LED_BLUE_RC2_WPU                WPUC2
#define LED_BLUE_RC2_ANS                ANSC2
#define LED_BLUE_RC2_SetHigh()    do { LATC2 = 1; } while(0)
#define LED_BLUE_RC2_SetLow()   do { LATC2 = 0; } while(0)
#define LED_BLUE_RC2_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED_BLUE_RC2_GetValue()         RC2
#define LED_BLUE_RC2_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define LED_BLUE_RC2_SetPullup()    do { WPUC2 = 1; } while(0)
#define LED_BLUE_RC2_ResetPullup()   do { WPUC2 = 0; } while(0)
#define LED_BLUE_RC2_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set LED_BLUE_RC2 aliases
#define LED_BLUE_RC2_TRIS               TRISC2
#define LED_BLUE_RC2_LAT                LATC2
#define LED_BLUE_RC2_PORT               RC2
#define LED_BLUE_RC2_WPU                WPUC2
#define LED_BLUE_RC2_ANS                ANSC2
#define LED_BLUE_RC2_SetHigh()    do { LATC2 = 1; } while(0)
#define LED_BLUE_RC2_SetLow()   do { LATC2 = 0; } while(0)
#define LED_BLUE_RC2_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED_BLUE_RC2_GetValue()         RC2
#define LED_BLUE_RC2_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define LED_BLUE_RC2_SetPullup()    do { WPUC2 = 1; } while(0)
#define LED_BLUE_RC2_ResetPullup()   do { WPUC2 = 0; } while(0)
#define LED_BLUE_RC2_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set LED_BLUE_RC2 aliases
#define LED_BLUE_RC2_TRIS               TRISC2
#define LED_BLUE_RC2_LAT                LATC2
#define LED_BLUE_RC2_PORT               RC2
#define LED_BLUE_RC2_WPU                WPUC2
#define LED_BLUE_RC2_ANS                ANSC2
#define LED_BLUE_RC2_SetHigh()    do { LATC2 = 1; } while(0)
#define LED_BLUE_RC2_SetLow()   do { LATC2 = 0; } while(0)
#define LED_BLUE_RC2_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define LED_BLUE_RC2_GetValue()         RC2
#define LED_BLUE_RC2_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define LED_BLUE_RC2_SetPullup()    do { WPUC2 = 1; } while(0)
#define LED_BLUE_RC2_ResetPullup()   do { WPUC2 = 0; } while(0)
#define LED_BLUE_RC2_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define LED_BLUE_RC2_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set FAN_CTRL_RC6 aliases
#define FAN_CTRL_RC6_TRIS               TRISC6
#define FAN_CTRL_RC6_LAT                LATC6
#define FAN_CTRL_RC6_PORT               RC6
#define FAN_CTRL_RC6_WPU                WPUC6
#define FAN_CTRL_RC6_ANS                ANSC6
#define FAN_CTRL_RC6_SetHigh()    do { LATC6 = 1; } while(0)
#define FAN_CTRL_RC6_SetLow()   do { LATC6 = 0; } while(0)
#define FAN_CTRL_RC6_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define FAN_CTRL_RC6_GetValue()         RC6
#define FAN_CTRL_RC6_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define FAN_CTRL_RC6_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define FAN_CTRL_RC6_SetPullup()    do { WPUC6 = 1; } while(0)
#define FAN_CTRL_RC6_ResetPullup()   do { WPUC6 = 0; } while(0)
#define FAN_CTRL_RC6_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define FAN_CTRL_RC6_SetDigitalMode()   do { ANSC6 = 0; } while(0)


// get/set OUT_EXTRA_RC7 aliases
#define OUT_EXTRA_RC7_LAT                LATC7
#define OUT_EXTRA_RC7_PORT               RC7
#define OUT_EXTRA_RC7_WPU                WPUC7
#define OUT_EXTRA_RC7_ANS                ANSC7
#define OUT_EXTRA_RC7_SetHigh()    do { LATC7 = 1; } while(0)
#define OUT_EXTRA_RC7_SetLow()   do { LATC7 = 0; } while(0)
#define OUT_EXTRA_RC7_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define OUT_EXTRA_RC7_GetValue()         RC7

#define OUT_EXTRA_RC7_SetPullup()    do { WPUC7 = 1; } while(0)
#define OUT_EXTRA_RC7_ResetPullup()   do { WPUC7 = 0; } while(0)
#define OUT_EXTRA_RC7_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define OUT_EXTRA_RC7_SetDigitalMode()   do { ANSC7 = 0; } while(0)



/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/