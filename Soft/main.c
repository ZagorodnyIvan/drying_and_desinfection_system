#include <main.h>
#include <stdlib.h>
#include <stdio.h>

#define ADCMAX 255

int16 adc_value;

#int_TIMER0
void  TIMER0_isr(void)
{
}

#int_EXT
void  EXT_isr(void)
{
}

void init()
{
   setup_oscillator (OSC_8MHZ);
   setup_adc_ports (AN0, VSS_VDD);
   setup_adc (ADC_CLOCK_INTERNAL|ADC_TAD_MUL_0);
   setup_timer_0 (RTCC_INTERNAL|RTCC_DIV_32);         //1.0 s overflow
   enable_interrupts (int_TIMER0);
   enable_interrupts (int_EXT);
   enable_interrupts (GLOBAL);
}

int8 time_leds()
{
   if (0 < adc_value < 80) return 1;
   else if (80 < adc_value < 128) return 2;
   else if (128 < adc_value < ADCMAX) return 3;
}

void main()
{
   init();
   set_adc_channel(0);
   delay_us(15);

   while(TRUE)
   {
      adc_value = read_adc(ADC_START_AND_READ);
      
      switch (time_leds)
      {
         case 1:
            output_high(PIN_B1);
            output_low(PIN_B2);
            output_low(PIN_B3);
         break;
         
         case 2:
            output_high(PIN_B1);
            output_high(PIN_B2);
            output_low(PIN_B3);
         break;
         
         case 3:
            output_high(PIN_B1);
            output_high(PIN_B2);
            output_high(PIN_B3);
         break;
         
         default:
            output_low(PIN_B1);
            output_low(PIN_B2);
            output_low(PIN_B3);
         break;
      }
   }
}

