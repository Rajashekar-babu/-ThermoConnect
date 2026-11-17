#include <lpc21xx.h>
#include "uart.h"
#include "delay.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "esp01.h"
#include "esp01_defines.h"

s32 remote_setpoint,data=20;

int main()
{
    UART0_Init();
    InitLCD();
    delay_ms(1000);
L1: Clear_Buffer();
    StrLCD("AT+CWQAP");
    U0_TxStr("AT+CWQAP\r\n");
    if(!waitforresponse("WIFI DISCONNECT", 2000))
    {
         goto L1;
    }
L2: Clear_Buffer();
    CmdLCD(CLEAR_LCD);
    StrLCD("AT");
    U0_TxStr("AT\r\n");
    if(!waitforresponse("OK", 1500))
    {
        goto L2;
    }
    
L3: Clear_Buffer();
    CmdLCD(CLEAR_LCD);
    StrLCD("ATE0");
    U0_TxStr("ATE0\r\n");
    if(!waitforresponse("OK", 1500))
    {
        goto L3;
    }
    
L4: Clear_Buffer();
    CmdLCD(CLEAR_LCD);
    U0_TxStr("AT+CIPMUX=0\r\n");
    StrLCD("AT+CIPMUX=0");
    if(!waitforresponse("OK", 1500))
    {
        goto L4;
    }
L5: Clear_Buffer();
    CmdLCD(CLEAR_LCD);
    U0_TxStr("AT+CWMODE=1\r\n");
    StrLCD("AT+CWMODE=1");
    //while(i<2);
    if(!waitforresponse("OK", 1500))
    {
        goto L5;
    }
L6: Clear_Buffer();
    CmdLCD(CLEAR_LCD);
    StrLCD("AT+CWJAP=");
    U0_TxStr("AT+CWJAP=\"WIFI_SSID\",\"WIFI_PASSWORD\"\r\n");
    if(!waitforresponse("WIFI CONNECTED", 3000))
    {
        goto L6;
    }
    Clear_Buffer();
    if(!waitforresponse("WIFI GOT IP", 1000))
    {
        goto L6;
    }
    Clear_Buffer();
    if(!waitforresponse("OK", 1000))
    {
        goto L6;
    } 
    while(1)
    {
				CmdLCD(CLEAR_LCD);
				StrLCD("Cloud Connecting...");
        if(thinkspeak_write(TS1_WRITE_API_KEY,data))    
        {
            CmdLCD(CLEAR_LCD);
            StrLCD("Data Transmited");
            CmdLCD(GOTO_LINE2_POS0);
            U32LCD(data);
        }
        else
        {
            CmdLCD(CLEAR_LCD);
            StrLCD("Trans ERROR");
        }
        data=data+2;
        delay_ms(15000);
				CmdLCD(CLEAR_LCD);
        StrLCD("Cloud Connecting...");
        remote_setpoint = thinkspeak_read(TS2_CHANNEL_ID, TS2_READ_API_KEY);
        if (remote_setpoint != -1)
        {
            CmdLCD(CLEAR_LCD);
            StrLCD("Data Recieved");
            CmdLCD(GOTO_LINE2_POS0);
            U32LCD(remote_setpoint);
        }
        else
        {
            CmdLCD(CLEAR_LCD);
            StrLCD("RECEV ERROR");
        }
				delay_ms(15000);
    }
}
