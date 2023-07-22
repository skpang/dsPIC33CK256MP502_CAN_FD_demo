

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef BOARD_SKP__H
#define	BOARD_SKP__H
#include "mcc_generated_files/system/pins.h"
#include <xc.h> // include processor files - each processor file is guarded.  

#define FIRMWARE_VER			2
#define HARDWARE_VER			4

void printf_uart2 (char *s);

struct CAN_MSG_FIELD_skp 
{
    unsigned int eid:1;       /**< Defines the message ID type as Standard ID or Extended ID */
    unsigned int cfd:1;       /**< Defines the message type as CAN 2.0 Format or CAN_FD Format */
    unsigned int brs:1;       /**< Enables or Disables the Bit Rate Switch */
    unsigned int spare1:1;          
    unsigned int spare2:1;         
    unsigned int spare3:1;        
    unsigned int spare4:1;          
    unsigned int spare5:1;          
};



typedef struct {
    uint32_t can_tx_id;
    uint32_t can_rx_id;
	uint8_t can_baudrate;
    uint8_t uart_baudrate;
    struct CAN_MSG_FIELD_skp field; 
	

    
} CAN_IO_BOARD_T;

typedef enum{
    UART_9600BPS,
    UART_14400BPS,
    UART_19200BPS,
    UART_38400BPS,
    UART_57600BPS,
    UART_115200BPS,
}UART_NBR;



void board_init_skp(void);
void check_factory_reset(void);
void set_uart_baudrate();

inline static void LED_R_off(void)
{
	
    LED_R_SetHigh();
}

inline static void LED_G_off(void)
{
	LED_G_SetHigh();
}


inline static void LED_B_off(void)
{
	LED_B_SetHigh(); 
}

inline static void LED_R_on(void)
{
	LED_R_SetLow();
}

inline static void LED_G_on(void)
{
	LED_G_SetLow();
}

inline static void LED_B_on(void)
{
	LED_B_SetLow();
}
inline static void LED_B_toggle(void)
{
	LED_B_Toggle();
}


#endif	/* XC_HEADER_TEMPLATE_H */

