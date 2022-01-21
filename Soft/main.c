#include <main.h>
#include <stdlib.h>
#include <stdio.h>

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

#int_TIMER0
void  TIMER0_isr(void){
   
}

#int_EXT
void  EXT_isr(void)
{
}

void main()
{
   init();
   while(true){
      //Time selection stage
      unsigned int8 adc_lecture = adc_read_data();
      time_leds(adc_lecture);
      //Function selection stage
      if(confirm_pressed(UVBUTTON)) output_high(UVONFLAG);
      if(confirm_pressed(HEATERBUTTON)) output_high(HEATERONFLAG);
      //while(!confirm_pressed(STARTBUTTON)) blinkLed();             for the future...
   }
}

unsigned int8 adc_value(){
   unsigned int8 value;
   set_adc_channel(0);
   delay_us(20);
   value = read_adc(ADC_START_AND_READ);
   return value;
}

unsigned int8 adc_read_data()
{
   unsigned int8 value = adc_value();
   unsigned int8 time_leds_value;
   if (2 < value <= (ADCMAX/3)) time_leds_value = 1;
   else if ((ADCMAX/3) < value <= (ADCMAX/2)) time_leds_value = 2;
   else if ((ADCMAX/2) < value < ADCMAX) time_leds_value = 3;
   else return 0;
   return time_leds_value;
}

void time_leds(unsigned int8 time_leds_value){
   switch(time_leds_value){
         case 0:
            output_low(LED1M);
            output_low(LED3M);
            output_low(LED5M);
            break;
            
         case 1:
            output_high(LED1M);
            output_low(LED3M);
            output_low(LED5M);
            break;
         
         case 2:
            output_high(LED1M);
            output_high(LED3M);
            output_low(LED5M);
            break;
         
         case 3:
            output_high(LED1M);
            output_high(LED3M);
            output_high(LED5M);
            break;
   }
}

int1 confirm_pressed(unsigned int16 button){
  if(input(button) == 1){
      delay_ms(10);
      if(input(button)== 0) return 1;
      else return 0;
   }
   else return 0;
}
