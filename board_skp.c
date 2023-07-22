#include <stdio.h>
#include "mcc_generated_files/system/pins.h"

#include "mcc_generated_files/uart/uart1.h"
#include "board_skp.h"


void board_init_skp(void)
{
    LED_R_on();
    DELAY_milliseconds(300);
    LED_R_off();
    
    LED_G_on();
    DELAY_milliseconds(300);    
    LED_G_off();
    
    LED_B_on();
    DELAY_milliseconds(300);    
    LED_B_off();
}

