#include <18F4620.h>
#device ADC=8

#FUSES NOWDT                    //No Watch Dog Timer

#device ICD=TRUE
#use delay(internal=8000000)
#use rs232(baud=9600,parity=N,bits=8,stream=PORT1,FORCE_SW)
