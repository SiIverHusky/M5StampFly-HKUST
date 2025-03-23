#include "Bitcraze_PMW3901.h"
#include <Arduino.h>
#include "driver/i2c.h"
#include <driver/spi_master.h>
#include "driver/gpio.h"
#include "optical_flow.h"


of i;


void optical_flow_init(){    
    if(i.begin()){
        USBSerial.printf("optical_flow_sucess\n");
        //optical_flow.enableFrameBuffer();
        i.setLed(true);
    }
    else{
        USBSerial.printf("optical_flow_fail\n");
        while(1){

        }
    }
}

void of_print_data(){
    int16_t x = 0;
    int16_t y = 0;
    i.setLed(true);
    i.readMotionCount(&x,&y);
    USBSerial.printf("x %hd , y %hd \n",x,y);
}
