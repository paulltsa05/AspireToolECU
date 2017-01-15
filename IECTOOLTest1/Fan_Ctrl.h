/* 
 * File:   Fan_Ctrl.h
 * Author: kpit
 *
 * Created on 25 July, 2016, 11:41 PM
 */

#ifndef FAN_CTRL_H
#define	FAN_CTRL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>     
#include "mcc_generated_files/mcc.h"
    
 
   
extern char FanStatusBusy(void);
extern char FanStartConfig(unsigned char FanONDurationSec);
extern void Fan_Control_Sec(void);


#ifdef	__cplusplus
}
#endif

#endif	/* FAN_CTRL_H */

