#include "CommunicationManager.h"
#include "main.h"
#include "Buzzer_Ctrl.h"
#include "LED_Ctrl.h"
#include "Fan_Ctrl.h"
//#include <delay.h>

#define EEPROM_ACCESS_LENGTH 16

unsigned char RxFrameDecodeState=0, RxFrameType='r',RxFrameDataLen=0,RxFrameDataLenCnt=0;
unsigned char SetLEDcolor='R', SetLedONDurationSec=0, SetLedONNumBlink=0;
unsigned char SetBuzzDurationSec=0, SetBuzzNumBeep=0;
unsigned char SetFANOnDurationSec=0;

unsigned char eepromWriteLen=0,eepromWriteData[EEPROM_ACCESS_LENGTH];
unsigned char eepromReadLen=0,eepromReadData[EEPROM_ACCESS_LENGTH];
unsigned int eepromWriteAddr=0,eepromReadAddr=0;
unsigned char CommandError=0;


unsigned char ChannelNumber=0,ChannelNumberChar='x';//this channel number is share by analog and digital input
unsigned int AnalogSenseRaw=0x0000;
unsigned char DigitalIN=0,AnalogSenseRawByte[2];

unsigned char RXChecksum=0,Checksum=0;
unsigned char highByteChar=0,lowByteChar=0;
unsigned char txPacketlength=0;

unsigned char char2bytetovalue(unsigned char highBchar,unsigned char LowBchar,unsigned char *cksum);
unsigned char char1bytetovalue(unsigned char LowBChar,unsigned char *cksum);
unsigned char chartovalue(unsigned char charNibble);
unsigned char valuetocharHighNibble(unsigned char hexvalue);
unsigned char valuetocharLowNibble(unsigned char hexvalue);
unsigned char valtoasciichar(unsigned char hexvalue1);

void PackageTxResponseData(unsigned char frameType,unsigned char *data,unsigned char dataLen);
void PackageTxResponseACK(unsigned char frameType);
void PackageTxResponseNACK(unsigned char frameType);

void ProtocolManager(void)
{
    unsigned char k=0;
    switch(RxFrameDecodeState)
    {
        case 0: if(EUSART_Read()=='$' && EUSART_Read()=='$')
                {
                    RxFrameDecodeState=1;
                    RxFrameDataLenCnt=2;
                    Checksum=0;
                }
                break;
                
        case 1: RxFrameType=EUSART_Read();
                Checksum+=RxFrameType;
                if((RxFrameType=='r')||(RxFrameType=='w')||(RxFrameType=='A')||(RxFrameType=='I')||(RxFrameType=='B')||(RxFrameType=='L')||(RxFrameType=='F')||(RxFrameType=='R'))
                {
                    RxFrameDecodeState=2;
                    RxFrameDataLenCnt=RxFrameDataLenCnt+1;
                }
                else
                {
                    RxFrameDecodeState=0;
                }
                break;
                
        case 2: highByteChar=EUSART_Read();
                lowByteChar=EUSART_Read();
                RxFrameDataLen=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                RxFrameDataLenCnt=RxFrameDataLenCnt+2;
                RxFrameDecodeState=3;
                break;
                
        case 3: if(RxFrameType=='r')
                {
                    RxFrameDecodeState=4;
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    eepromReadAddr=((unsigned int)char2bytetovalue(highByteChar,lowByteChar,&Checksum))& 0x00FF;
                    RxFrameDataLenCnt=RxFrameDataLenCnt+2;
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    eepromReadLen=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                    RxFrameDataLenCnt=RxFrameDataLenCnt+2;
                    CommandError=0;
                    if(eepromReadLen>EEPROM_ACCESS_LENGTH)
                    {
                        CommandError=1;
                        DelayMsecCount=0;//wait with '\n' or with timeout 20msec
                        while(EUSART_Read()!='\n'){if(DelayMsecCount>20){break;}};
                        PackageTxResponseNACK(RxFrameType);//it send Nack response directly
                        //TO CHECK: This might not work well for half duplex RS485
                        RxFrameDecodeState=0;//reset state
                    }
                }
                else if(RxFrameType=='w')//EEPROM Write 
                {
                    RxFrameDecodeState=4;
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    eepromWriteAddr=((unsigned int)char2bytetovalue(highByteChar,lowByteChar,&Checksum))& 0x00FF;
                    RxFrameDataLenCnt=RxFrameDataLenCnt+2;
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    eepromWriteLen=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                    RxFrameDataLenCnt=RxFrameDataLenCnt+2;
                    CommandError=0;
                    if(eepromWriteLen>EEPROM_ACCESS_LENGTH)
                    {
                        CommandError=1;        
                        DelayMsecCount=0;//wait with '\n' or with timeout 20msec
                        while(EUSART_Read()!='\n'){if(DelayMsecCount>20){break;}};
                        PackageTxResponseNACK(RxFrameType);//it send Nack response directly
                        //TO CHECK: This might not work well for half duplex RS485
                        RxFrameDecodeState=0;//reset state
                    }
                    else
                    {
                        for(k=0;k<eepromWriteLen;k++)
                        {
                            highByteChar=EUSART_Read();
                            lowByteChar=EUSART_Read();
                            eepromWriteData[k]=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                            RxFrameDataLenCnt=RxFrameDataLenCnt+2;

                        }    
                    }
                    
                }
                else if(RxFrameType=='A')
                {
                    RxFrameDecodeState=4;
                    lowByteChar=EUSART_Read();
                    ChannelNumberChar=lowByteChar;
                    ChannelNumber=char1bytetovalue(lowByteChar,&Checksum);
                    RxFrameDataLenCnt=RxFrameDataLenCnt + 1;
                }
                else if(RxFrameType=='I')
                {
                    RxFrameDecodeState=4;
                    lowByteChar=EUSART_Read();
                    ChannelNumberChar=lowByteChar;
                    ChannelNumber=char1bytetovalue(lowByteChar,&Checksum);
                    RxFrameDataLenCnt=RxFrameDataLenCnt + 1;
                }    
                else if(RxFrameType=='L')
                {
                    RxFrameDecodeState=4;
                    SetLEDcolor=EUSART_Read();
                    Checksum+=SetLEDcolor;
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    SetLedONDurationSec=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    SetLedONNumBlink=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                    RxFrameDataLenCnt=RxFrameDataLenCnt + 5;    //5 EUSART_Read())
                }
                else if(RxFrameType=='B')
                {
                    RxFrameDecodeState=4;
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    SetBuzzDurationSec=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    SetBuzzNumBeep=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                    RxFrameDataLenCnt=RxFrameDataLenCnt + 4; 
                }
                else if(RxFrameType=='F')
                {
                    RxFrameDecodeState=4;
                    highByteChar=EUSART_Read();
                    lowByteChar=EUSART_Read();
                    SetFANOnDurationSec=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&Checksum);
                    RxFrameDataLenCnt=RxFrameDataLenCnt + 2; 
                }        
                else
                {
                    RxFrameDataLenCnt=0;    
                    RxFrameDecodeState=0;
                }
                break;
                
        case 4: //CHECKSUM and TRAIL SECTION
                highByteChar=EUSART_Read();
                lowByteChar=EUSART_Read();
                RXChecksum=(unsigned char)char2bytetovalue(highByteChar,lowByteChar,&k);
                RxFrameDataLenCnt=RxFrameDataLenCnt+2;
                Checksum=~Checksum;//checksum does not include the checksum byte
                if((RXChecksum==(Checksum)) && (EUSART_Read()=='#') && (EUSART_Read()=='\r') && (EUSART_Read()=='\n'))
                {   //Take action only after receive full frame receive with correct Checksum
                    RxFrameDecodeState=5;
                    RxFrameDataLenCnt=RxFrameDataLenCnt+3;                
                }
                else
                {
                    RxFrameDataLenCnt=0;    
                    RxFrameDecodeState=0;
                }
 
                break;
                
        case 5: //RX COMMAND PACKAGE IS VALIDATED AND ACTION ARE DONE IN THIS STATE
                if(RxFrameDataLenCnt==RxFrameDataLen)//check data length 
                {    
                    if(RxFrameType=='r')
                    {
                        for(k=0;k<eepromReadLen;k++)
                        {
                            eepromReadAddr=eepromReadAddr | 0xF000;
                            eepromReadData[k]=DATAEE_ReadByte(eepromReadAddr+k);
                        } 
                        PackageTxResponseData(RxFrameType,eepromReadData,eepromReadLen);
                    }
                    else if(RxFrameType=='w')
                    {
                        for(k=0;k<eepromWriteLen;k++)
                        {
                            eepromWriteAddr=eepromWriteAddr | 0xF000;
                            DATAEE_WriteByte((eepromWriteAddr+k), eepromWriteData[k]);
                        }  
                        PackageTxResponseACK(RxFrameType);
                    }
                    else if(RxFrameType=='A')
                    {
                        if((ChannelNumberChar=='0')||(ChannelNumberChar=='*'))//Temperature Sense
                        {
                            //adc_result_t ADC_GetConversion(adc_channel_t channel)
                            AnalogSenseRaw=ADC_GetConversion(TEMP_J6_4_ANA2);
                            AnalogSenseRawByte[0]=(unsigned char)(AnalogSenseRaw & 0x00FF);
                            AnalogSenseRawByte[1]=(unsigned char)((AnalogSenseRaw>>8) & 0x00FF);   
                            PackageTxResponseData(RxFrameType,AnalogSenseRawByte,2);
                        }
                        else
                        {
                            PackageTxResponseNACK(RxFrameType);
                        }
                    }
                    else if(RxFrameType=='I')//MULTIFUNC_SW_ANC4
                    {
                        DigitalIN=0x00;
                        AnalogSenseRaw=ADC_GetConversion(MULTIFUNC_SW_ANC4);
                        if(AnalogSenseRaw > 0x100)
                            DigitalIN |=0x01;
                        AnalogSenseRaw=ADC_GetConversion(DIR_SW_ANC5);
                        if(AnalogSenseRaw > 0x100)
                            DigitalIN |=0x02;
                        
                        if(ChannelNumberChar=='0')//Multi Function switch
                        {
                            //DigitalIN=MULTIFUNC_SW_RC4_GetValue();
                            DigitalIN=DigitalIN&0x01;
                            PackageTxResponseData(RxFrameType,&DigitalIN,1);
                        }
                        else if(ChannelNumberChar=='1')//Direction switch
                        {
                            //DigitalIN=DIR_SW_RC5_GetValue();
                            DigitalIN=(DigitalIN>>1)&0x01;
                            PackageTxResponseData(RxFrameType,&DigitalIN,1);
                        }
                        else if(ChannelNumberChar=='*')//get direction and switch together
                        {
                            //DigitalIN=MULTIFUNC_SW_RC4_GetValue();//bit0-switch,bit1-direction
                            //DigitalIN=(((DIR_SW_RC5_GetValue()<<1)&0x02) | DigitalIN) & 0x03;
                            DigitalIN=(DigitalIN)&0x03;
                            PackageTxResponseData(RxFrameType,&DigitalIN,1);
                        }
                        else
                        {
                            PackageTxResponseNACK(RxFrameType);
                        }    
                    }        
                    else if(RxFrameType=='L')
                    {
                        switch(SetLEDcolor)
                        {
                            case 'R':SetLEDcolor=LED_RED;break;
                            case 'G':SetLEDcolor=LED_GREEN;break;
                            case 'B':SetLEDcolor=LED_BLUE;break;
                        }
  
                        //char LedONStartConfig(unsigned char LEDcolor, unsigned char LedONDurationSec, unsigned char LedONNumBlink)
                        if(LedONStartConfig(SetLEDcolor, SetLedONDurationSec, SetLedONNumBlink) != 0)
                            PackageTxResponseACK(RxFrameType);
                        else
                            PackageTxResponseNACK(RxFrameType);
                    }
                    else if(RxFrameType=='B')
                    {
                          //(unsigned char BuzzDurationSec, unsigned char BuzzNumBeep);
                        if(BuzzerStartConfig(SetBuzzDurationSec,SetBuzzNumBeep) != 0)
                            PackageTxResponseACK(RxFrameType);
                        else
                            PackageTxResponseNACK(RxFrameType);
                    }
                    else if(RxFrameType=='F')
                    {
                          //char FanStartConfig(unsigned char FanONDurationSec)
                        if(FanStartConfig(SetFANOnDurationSec) != 0)
                            PackageTxResponseACK(RxFrameType);
                        else
                            PackageTxResponseNACK(RxFrameType);
                    }
                                        
                }    

                RxFrameDataLenCnt=0;    
                RxFrameDecodeState=0;
                              
                break;

        default:RxFrameDecodeState=0;
                RxFrameDataLenCnt=0;
                break;
    }
}

unsigned char valtoasciichar(unsigned char hexvalue1)
{   
    unsigned char hexval='0';
    switch((unsigned char)hexvalue1)
    {
        case 0x00: hexval= '0'; break;
        case 0x01: hexval= '1'; break;
        case 0x02: hexval= '2'; break;
        case 0x03: hexval= '3'; break;
        case 0x04: hexval= '4'; break;
        case 0x05: hexval= '5'; break;
        case 0x06: hexval= '6'; break;
        case 0x07: hexval= '7'; break;
        case 0x08: hexval= '8'; break;
        case 0x09: hexval= '9'; break;
        case 0x0A: hexval= 'A'; break;
        case 0x0B: hexval= 'B'; break;
        case 0x0C: hexval= 'C'; break;
        case 0x0D: hexval= 'D'; break;
        case 0x0E: hexval= 'E'; break;
        case 0x0F: hexval= 'F'; break;
        default : break;             
    }
    return hexval;
}

unsigned char chartovalue(unsigned char charNibble)
{
    unsigned char hexval=0x00;
    switch((unsigned char)charNibble)
    {
        case '0': hexval= 0x00; break;
        case '1': hexval= 0x01; break;
        case '2': hexval= 0x02; break;
        case '3': hexval= 0x03; break;
        case '4': hexval= 0x04; break;
        case '5': hexval= 0x05; break;
        case '6': hexval= 0x06; break;
        case '7': hexval= 0x07; break;
        case '8': hexval= 0x08; break;
        case '9': hexval= 0x09; break;
        case 'A': hexval= 0x0A; break;
        case 'B': hexval= 0x0B; break;
        case 'C': hexval= 0x0C; break;
        case 'D': hexval= 0x0D; break;
        case 'E': hexval= 0x0E; break;
        case 'F': hexval= 0x0F; break;
        default : break;             
    }
    return hexval;
}

unsigned char char2bytetovalue(unsigned char highBchar,unsigned char LowBchar,unsigned char *cksum)
{
    unsigned char valuehex;
    //calculate continuing checksum
    (*cksum)=(*cksum)+(highBchar+LowBchar);
    //combine 2 hex byte ASCII
    valuehex=(unsigned char)(((chartovalue(highBchar))<<4)& 0xF0)+(chartovalue(LowBchar)& 0x0F);
    return valuehex;
}
unsigned char char1bytetovalue(unsigned char LowBChar,unsigned char *cksum)
{
    unsigned char valuehex;
    //calculate continuing checksum
    (*cksum)=(*cksum)+(LowBChar);
    //combine 1 nibble of hex byte ASCII
    valuehex=(unsigned char)(chartovalue(LowBChar)& 0x0F);
    return valuehex;
}

unsigned char valuetocharHighNibble(unsigned char hexvalue)
{
    unsigned char hexval;
    hexval=(unsigned char)((unsigned char)(hexvalue>>4) & 0x0F);
    hexval=valtoasciichar(hexval);
    return hexval;
    
}

unsigned char valuetocharLowNibble(unsigned char hexvalue)
{
    unsigned char hexval;
    hexval=(unsigned char)((unsigned char)(hexvalue) & 0x0F);
    hexval=valtoasciichar(hexval); 
    return hexval;
}

void PackageTxResponseData(unsigned char frameType,unsigned char *data,unsigned char dataLen)
{
    //Package Response frame and start sending
    unsigned char i;
    //DelayMsecCount=0;
    //while(DelayMsecCount>10);//wait 5 msec

    if(dataLen==0)
    {
        PackageTxResponseNACK(frameType);        
    }
    else
    {
        
        EUSART_RX_Disable();
        RS422_TXEN_RB6_SetHigh(); // ensure TX on RS485 is enable.

      //  DelayMsecCount=0;
      //  while(DelayMsecCount>10);//5wait 6 msec
        EUSART_TX_Completed();    
       // EUSART_Write('g');
       // EUSART_Write('h');
       // EUSART_Write('h');
        EUSART_Write('$');
        EUSART_Write('$');//skip $$ start sequence for checksum.
        Checksum=0;

        EUSART_Write('O');//command response OK
        Checksum+='O';
        
        if((frameType=='A')||(frameType=='I'))//Note channel number is a Nibble for analog and input
        {
            txPacketlength=12+(dataLen*2);//see RS485 protocol command example document
        }
        else if(frameType=='r')//For EEPROM data Length is a byte = 2 Nibble
        {
            txPacketlength=13+(dataLen*2);//see RS485 protocol command example document
        }
        else
            txPacketlength=11;//unimplemented packaging
        
        highByteChar=valuetocharHighNibble(txPacketlength);
        Checksum+=highByteChar;
        lowByteChar=valuetocharLowNibble(txPacketlength);
        Checksum+=lowByteChar;
        EUSART_Write(highByteChar);//data length in frame as hex ascii
        EUSART_Write(lowByteChar);//data length in frame as hex ascii


        EUSART_Write(frameType);//which command ACK
        Checksum+=frameType;

        if((frameType=='A')||(frameType=='I'))
        {   
            Checksum+=ChannelNumberChar;
            EUSART_Write(ChannelNumberChar);//for analog/digital which channel
        }
        else if(frameType=='r')//for eeprom read
        { 
            highByteChar=valuetocharHighNibble(dataLen);
            Checksum+=highByteChar;
            lowByteChar=valuetocharLowNibble(dataLen);
            Checksum+=lowByteChar;
            EUSART_Write(highByteChar);
            EUSART_Write(lowByteChar);
        }
        
        for(i=0;i<dataLen;i++) //data 1 byte = 2 ascii nibble
        {    
           
            highByteChar=valuetocharHighNibble(*(data+i));
            Checksum+=highByteChar;
            lowByteChar=valuetocharLowNibble(*(data+i));
            Checksum+=lowByteChar;
            EUSART_Write(highByteChar);//data length in frame as hex ascii
            EUSART_Write(lowByteChar);//data length in frame as hex ascii
        
        }
      
        Checksum=(unsigned char)(~Checksum);// transmit checksum as char ascii
        highByteChar=valuetocharHighNibble(Checksum);
        lowByteChar=valuetocharLowNibble(Checksum);
        EUSART_Write(highByteChar);//checksum in frame as hex ascii
        EUSART_Write(lowByteChar);//checksum in frame as hex ascii

        //packet trail sequence
        EUSART_Write('#');
        EUSART_Write('\r');
        EUSART_Write('\n');

        EUSART_TX_Completed();
        RS422_TXEN_RB6_SetLow(); // ensure TX on RS485 is disabled.
        EUSART_RX_Enable();
   
    }
}
void PackageTxResponseACK(unsigned char frameType)
{

    EUSART_RX_Disable();
    RS422_TXEN_RB6_SetHigh(); // ensure TX on RS485 is enable.

    EUSART_TX_Completed();    

    EUSART_Write('$');
    EUSART_Write('$');//skip $$ start sequence for checksum.
    Checksum=0;

    EUSART_Write('O');//command response OK
    Checksum+='O';
    txPacketlength=11;//or 0x0B hex
    highByteChar=valuetocharHighNibble(txPacketlength);
    Checksum+=highByteChar;
    lowByteChar=valuetocharLowNibble(txPacketlength);
    Checksum+=lowByteChar;
    EUSART_Write(highByteChar);//data length in frame as hex ascii
    EUSART_Write(lowByteChar);//data length in frame as hex ascii

    EUSART_Write(frameType);//which command response NOT OK
    Checksum+=frameType;
        
    Checksum=~Checksum;// transmit checksum as char ascii
    highByteChar=valuetocharHighNibble(Checksum);
    lowByteChar=valuetocharLowNibble(Checksum);
    EUSART_Write(highByteChar);//checksum in frame as hex ascii
    EUSART_Write(lowByteChar);//checksum in frame as hex ascii
    
    //packet trail sequence
    EUSART_Write('#');
    EUSART_Write('\r');
    EUSART_Write('\n');

    EUSART_TX_Completed();
    RS422_TXEN_RB6_SetLow(); // ensure TX on RS485 is disabled.
    EUSART_RX_Enable();
}

void PackageTxResponseNACK(unsigned char frameType)
{

    EUSART_RX_Disable();
    RS422_TXEN_RB6_SetHigh(); // ensure TX on RS485 is enable.

    EUSART_TX_Completed();    

    EUSART_Write('$');
    EUSART_Write('$');//skip $$ start sequence for checksum.
    Checksum=0;

    EUSART_Write('N');//command response not OK
    Checksum+='N';
    txPacketlength=11;//or 0x0B hex
    highByteChar=valuetocharHighNibble(txPacketlength);
    Checksum+=highByteChar;
    lowByteChar=valuetocharLowNibble(txPacketlength);
    Checksum+=lowByteChar;
    EUSART_Write(highByteChar);//data length in frame as hex ascii
    EUSART_Write(lowByteChar);//data length in frame as hex ascii

    EUSART_Write(frameType);//which command response NOT OK
    Checksum+=frameType;
        
    Checksum=~Checksum;// transmit checksum as char ascii
    highByteChar=valuetocharHighNibble(Checksum);
    lowByteChar=valuetocharLowNibble(Checksum);
    EUSART_Write(highByteChar);//checksum in frame as hex ascii
    EUSART_Write(lowByteChar);//checksum in frame as hex ascii
    
    //packet trail sequence
    EUSART_Write('#');
    EUSART_Write('\r');
    EUSART_Write('\n');

    EUSART_TX_Completed();
    RS422_TXEN_RB6_SetLow(); // ensure TX on RS485 is disabled.
    EUSART_RX_Enable();
}
