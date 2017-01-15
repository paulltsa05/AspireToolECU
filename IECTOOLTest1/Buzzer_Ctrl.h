/* 
 * File:   Buzzer_Ctrl.h
 * Author: kpit
 *
 * Created on July 24, 2016, 10:24 PM
 */

#ifndef BUZZER_CTRL_H
#define	BUZZER_CTRL_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <xc.h>     
#include "mcc_generated_files/mcc.h"


extern char BuzzerStartConfig(unsigned char BuzzDurationSec, unsigned char BuzzNumBeep);
extern void Buzzer_Control_msec(void);
extern char BuzzerStatusBusy(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BUZZER_CTRL_H */

