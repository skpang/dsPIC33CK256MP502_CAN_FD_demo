/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/can/can1.h"
#include "mcc_generated_files/can/can_types.h"
#include "mcc_generated_files/system/system.h"
#include "board_skp.h"

uint16_t led_blink_task;

uint16_t task1 = 0;
uint16_t task2 = 0;
uint16_t count = 0;
struct CAN_MSG_OBJ msg;

static uint8_t CAN1_DlcToDataBytesGet(const enum CAN_DLC dlc)
{
    static const uint8_t dlcByteSize[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return dlcByteSize[dlc];
}

/*
    Main application
*/void TMR1_TimeoutCallback(void)
{
    led_blink_task++;
    task1++;
    task2++;
}

static void can_tx(void)
{
    struct    CAN_MSG_OBJ Transmission;
    uint8_t Transmit_Data[64]={0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77};
     
    memset(Transmit_Data,0,sizeof(Transmit_Data));
     
    Transmit_Data[0]= count;
    Transmit_Data[1]= (0xff00 & count) >> 8;
    count ++;

    Transmission.field.brs = CAN_BRS_MODE; //CAN_NON_BRS_MODE;//CAN_BRS_MODE;
    Transmission.field.dlc = DLC_64; // DLC_8;//DLC_64;
    Transmission.field.formatType = CAN_FD_FORMAT; //CAN_2_0_FORMAT; //CAN_FD_FORMAT;
    Transmission.field.frameType = CAN_FRAME_DATA;
    Transmission.field.idType = CAN_FRAME_STD;
    Transmission.msgId = 0x7DF;
    Transmission.data = Transmit_Data;
    
    if(CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(CAN1_TXQ) & CAN_TX_FIFO_AVAILABLE))
        {
             CAN1_Transmit(CAN1_TXQ, &Transmission);
        }else printf("CAN TX error\n");
    
}

void can_event(void)
{
   uint8_t i,len;
   uint32_t id;
   
   if(CAN1_ReceivedMessageCountGet())
   {
        CAN1_Receive(&msg);
        id = msg.msgId;
        len = CAN1_DlcToDataBytesGet(msg.field.dlc);
       
        printf("ID: %x  Len: %d  Data: ", (uint16_t)msg.msgId,len);
        for(i=0;i<len;i++)
        {
            printf("%x ",msg.data[i]);
        
        }
        printf("\n");
    }
}

int main(void)
{
    SYSTEM_Initialize();
    
    board_init_skp();  // Flash board LEDs
    printf("\n\n***************************\ndsPIC33CK256MP502 CAN FD Demo skpang.co.uk 07/23\n");
 
    while(1)
    {
        can_event();  // Check for incoming CAN frames
        
        if(led_blink_task > 1000)
        {
            led_blink_task = 0;
            LED_G_Toggle();
           
        } 
        
        if(task1 > 500)
        {
            task1 = 0;
            can_tx();   // Sent CAN frame
        }
        
    }    
}