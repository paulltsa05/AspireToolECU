#include "Fan_Ctrl.h"

//Variables and function for FanON
static unsigned char Fan_ON=0,LedON_Duration_sec=0, LED_Sec_Cnt=0;

char FanStatusBusy(void)
{
    return Fan_ON;
}

//NOTE: FanONDurationSec < 60 
char FanStartConfig(unsigned char FanONDurationSec)
{
    if(Fan_ON!=1 && (FanONDurationSec!=0)&& (FanONDurationSec <= 60))
    {   
        Fan_ON=1;
        LED_Sec_Cnt=0;
        LedON_Duration_sec=FanONDurationSec;
        FAN_CTRL_RC6_SetHigh();
        return 1;
    }
    else
    {
        return 0;//error
    }
        
}

// call void LedON_Control_msec(void) function in 1msec
void Fan_Control_Sec(void)
{
        if(1==Fan_ON)//check if Enable
        {
            if(LED_Sec_Cnt++ == LedON_Duration_sec)
            {
                FAN_CTRL_RC6_SetLow();
                Fan_ON=0;
                LED_Sec_Cnt=0;
            }
        }
}
