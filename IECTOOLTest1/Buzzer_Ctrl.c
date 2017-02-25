#include "Buzzer_Ctrl.h"

//Variables and function for Buzzer
static unsigned char Buzzer_ON=0;
static unsigned int Buzzer_1msec_Cnt=0,Bbeep_tickPointMsec=0,Bbeep_tickPoint,Buzzer_Duration_1msec=0;

//char BuzzerStartConfig(unsigned char BuzzDurationSec, unsigned char BuzzNumBeep);
//void Buzzer_Control_1msec(void);
char BuzzerStatusBusy(void)
{
    return Buzzer_ON;
}

//NOTE: BuzzDurationSec < 60 
char BuzzerStartConfig(unsigned char BuzzDurationSec, unsigned char BuzzNumBeep)
{
    if(Buzzer_ON!=1 && (BuzzDurationSec!=0)&& (BuzzDurationSec <= 60))
    {   
        Buzzer_ON=1;
        TMR2_WriteTimer(0);
        TMR2_StartTimer();
        
        
        Buzzer_1msec_Cnt=0;
        Buzzer_Duration_1msec=((unsigned int)BuzzDurationSec)*1000;
        if(BuzzNumBeep > 1)
            Bbeep_tickPointMsec=(Buzzer_Duration_1msec/(((BuzzNumBeep-1)*2)+1));
        else
            Bbeep_tickPointMsec=Buzzer_Duration_1msec;
        
        Bbeep_tickPoint=Bbeep_tickPointMsec;
        return 1;
    }
    else
    {
        return 0;//error
    }
        
}

// call void Buzzer_Control_msec(void) function in 1msec
void Buzzer_Control_msec(void)
{
    if(1==Buzzer_ON)//check if Enable
    {   
      
        if(Buzzer_1msec_Cnt >= Bbeep_tickPoint)//toggle timer ON/OFF at beep points msec
        {
            TMR2_WriteTimer(0);
            TMR2_ToggleTimer();

            
            Bbeep_tickPoint=Bbeep_tickPoint+Bbeep_tickPointMsec;//increment for next beep
            TMR2_WriteTimer(0);
        }
        
        if(Buzzer_1msec_Cnt > Buzzer_Duration_1msec)//Stop at duration expire
        {
            TMR2_WriteTimer(0);
            TMR2_StopTimer();
            
            Buzzer_ON=0;
            Buzzer_1msec_Cnt=0;
        }
        
        Buzzer_1msec_Cnt++;
    }
    else
    {
        TMR2_StopTimer();
    }        
    
}
