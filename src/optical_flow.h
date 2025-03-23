
#include "Bitcraze_PMW3901.h"
#include "tof.hpp"
void of_print_data();
void optical_flow_init();

class of : public Bitcraze_PMW3901 {
    private :
        int16_t last_tick ;
        int16_t movement_x;
        int16_t movement_y;
    public:
        of(): Bitcraze_PMW3901(12){
            last_tick = esp_timer_get_time();
            movement_x = 0;
            movement_y = 0;
        }
        ~of(){}
        void track(){
            int16_t x = 0;
            int16_t y = 0;
            int16_t z = tof_bottom_get_range();// in mm
            setLed(true);
            readMotionCount(&x,&y);
            movement_y += x;
            movement_x += y;
            USBSerial.printf("x : %d y : %d z : %d \n", movement_y , movement_x,z);
            USBSerial.printf("x : %hd y : %hd\n", x , y);

            // int16_t x = 0;
            // int16_t y = 0;
            // setLed(true);
            // readMotionCount(&x,&y);
            // USBSerial.printf("x %hd , y %hd \n",x,y);
        }

    
};

extern of i;
