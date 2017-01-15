/* 
 * File:   LED_Ctrl.h
 * Author: kpit
 *
 * Created on 25 July, 2016, 10:12 PM
 */

#ifndef LED_CTRL_H
#define	LED_CTRL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>     
#include "mcc_generated_files/mcc.h"
    
#define LED_RED     0
#define LED_GREEN   1
#define LED_BLUE    2    
   
extern char LedONStatusBusy(void);
extern char LedONStartConfig(unsigned char LEDColor, unsigned char LedONDurationSec, unsigned char LedONNumBlink);
extern void LedON_Control_msec(void);

#ifdef	__cplusplus
}
#endif

#endif	/* LED_CTRL_H */

