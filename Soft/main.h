#include <18F4620.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES INTRC_IO                 //Internal RC Osc, no CLKOUT
#FUSES NOPROTECT                //Code not protected from reading
#FUSES IESO                     //Internal External Switch Over mode enabled
#FUSES NOBROWNOUT               //No brownout reset
#FUSES BORV21                   //Brownout reset at 2.1V
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
#FUSES STVREN                   //Stack full/underflow will cause reset
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOWRTD                   //Data EEPROM not write protected
#FUSES NOEBTR                   //Memory not protected from table reads
#FUSES NOCPB                    //No Boot Block code protection
#FUSES NOEBTRB                  //Boot block not protected from table reads
#FUSES NOWRTC                   //configuration not registers write protected
#FUSES NOWRTB                   //Boot block not write protected
#FUSES FCMEN                    //Fail-safe clock monitor enabled
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#FUSES PBADEN                   //PORTB pins are configured as analog input channels on RESET
#FUSES LPT1OSC                  //Timer1 configured for low-power operation
#FUSES MCLR                     //Master Clear pin enabled

#use delay(clock=8000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
/*===================================================
                     DEFINITIONS
-----------------------------------------------------*/

#define ADCMAX 255
#define LED1M PIN_B1
#define LED3M PIN_B2
#define LED5M PIN_B3
#define UVBUTTON PIN_A2
#define UVONFLAG PIN_D0
#define UVONRELAY PIN_A6
#define HEATERBUTTON PIN_A3
#define HEATERONFLAG PIN_D1
#define HEATERONRELAY PIN_C0
#define STARTBUTTON PIN_A5
#define STARTEDFLAG PIN_D2
#define DHTDATA PIN_A1
#define DHTLED PIN_D3
#define BUZZER PIN_D4

/*===================================================
                      FUNCTIONS
-----------------------------------------------------*/


