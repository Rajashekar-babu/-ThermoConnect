//esp01_test.c
//Simple ESP01 WiFi test - no LCD/keypad/EEPROM needed.
//Wire ESP01 to UART1 (as in esp01.c), USB-UART converter to UART0.
//Open a serial terminal on UART0 (9600 8N1) to watch the results.

#include <LPC21xx.h>
#include "types.h"
#include "uart.h"
#include "esp01.h"

int main(void)
{
    UART0_Init();
    U0_TxStr("\r\n--- ESP01 WiFi Test ---\r\n");

    //Step 1: is the module alive at all?
    U0_TxStr("1) AT (module alive?)... ");
    if (ESP01_SendCmd("AT", "OK", 2000))
        U0_TxStr("OK\r\n");
    else
        U0_TxStr("FAILED - check power/wiring/baud rate\r\n");

    //Step 2: set station mode
    U0_TxStr("2) AT+CWMODE=1 (station mode)... ");
    if (ESP01_SendCmd("AT+CWMODE=1", "OK", 2000))
        U0_TxStr("OK\r\n");
    else
        U0_TxStr("FAILED\r\n");

    //Step 3: join WiFi (edit WIFI_SSID / WIFI_PASSWORD in esp01.h first!)
    U0_TxStr("3) Joining WiFi (up to 15s)... ");
    if (ESP01_Init())
        U0_TxStr("CONNECTED\r\n");
    else
        U0_TxStr("FAILED - check SSID/PASSWORD in esp01.h\r\n");

    //Step 4: optional - actually post a test value to ThingSpeak Channel 1
    U0_TxStr("4) Posting test value (25) to ThingSpeak... ");
    if (ESP01_SendTempAlert(25, 0))
        U0_TxStr("OK - check your ThingSpeak channel\r\n");
    else
        U0_TxStr("FAILED - check internet/API key\r\n");

    U0_TxStr("--- Test complete ---\r\n");

    while (1);
}
