#include <main.h>
//!#include <stdlib.h>
//!#include <stdio.h>


//!unsigned int8 adc_value(){
//!   unsigned int8 value;
//!   value = read_adc(ADC_START_AND_READ);
//!   return value;
//!}

void leds(int1 a, int1 b, int1 c){
   output_bit(LED1M,a);
   output_bit(LED3M,b);
   output_bit(LED5M,c);
}
unsigned int8 read_data(int8 value)
{
   //int8 value = read_adc();
   
//!   unsigned int8 time_leds_value;
//!   if (2 < value <= (ADCMAX/3)) time_leds_value = 1;
//!   else if ((ADCMAX/3) < value <= (ADCMAX/2)) time_leds_value = 2;
//!   else if ((ADCMAX/2) < value < ADCMAX) time_leds_value = 3;
//!   else return 0;
//!   return time_leds_value;
   if (value <= (ADCMAX/3)) return 1;
   if (value <= (ADCMAX/2)) return 2;
   if (value <= ADCMAX) return 3;
   return 0;
}

void time_leds(unsigned int8 time_leds_value){
   switch(time_leds_value){
         case 0:
            leds(0,0,0);
            break;
            
         case 1:
            leds(1,0,0);
            break;
         
         case 2:
            leds(1,1,0);
            break;
         
         case 3:
            leds(1,1,1);
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

//!#int_TIMER0
//!void  TIMER0_isr(void){
//!   
//!}
//!
//!#int_EXT
//!void  EXT_isr(void)
//!{
//!}  
void init()
{
   setup_adc_ports(AN0|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2|ADC_TAD_MUL_0);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DIV_BY_1,199,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   enable_interrupts(INT_TIMER2);
   enable_interrupts(GLOBAL);
   setup_oscillator(OSC_8MHZ|OSC_INTRC|OSC_31250|OSC_PLL_OFF);
   //read_adc(ADC_START_AND_READ);
}

#int_TIMER2
void  TIMER2_isr(void) 
{

}



void main()
{
   init();
      while(true){
         //PAIN
         //Time selection stage
         unsigned int8 adc_lecture = read_data(read_adc());
         time_leds(adc_lecture);
         
         //Function selection stage
         if(confirm_pressed(UVBUTTON)) output_high(UVONFLAG);
         if(confirm_pressed(HEATERBUTTON)) output_high(HEATERONFLAG);
         //while(!confirm_pressed(STARTBUTTON)) blinkLed();             for the future...
      }
}
