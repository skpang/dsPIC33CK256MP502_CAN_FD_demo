/**
 * PINS Generated Driver Header File 
 * 
 * @file      pins.h
 *            
 * @defgroup  pinsdriver Pins Driver
 *            
 * @brief     The Pin Driver directs the operation and function of 
 *            the selected device pins using dsPIC MCUs.
 *
 * @skipline @version   Firmware Driver Version 1.0.2
 *
 * @skipline @version   PLIB Version 1.2.0
 *
 * @skipline  Device : dsPIC33CK256MP502
*/

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

#ifndef PINS_H
#define PINS_H
// Section: Includes
#include <xc.h>

// Section: Device Pin Macros

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of mode_pin to High
 * @pre      The RA0 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define mode_pin_SetHigh()          (_LATA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA0 GPIO Pin which has a custom name of mode_pin to Low
 * @pre      The RA0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define mode_pin_SetLow()           (_LATA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA0 GPIO Pin which has a custom name of mode_pin
 * @pre      The RA0 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define mode_pin_Toggle()           (_LATA0 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA0 GPIO Pin which has a custom name of mode_pin
 * @param    none
 * @return   none  
 */
#define mode_pin_GetValue()         _RA0

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of mode_pin as Input
 * @param    none
 * @return   none  
 */
#define mode_pin_SetDigitalInput()  (_TRISA0 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA0 GPIO Pin which has a custom name of mode_pin as Output
 * @param    none
 * @return   none  
 */
#define mode_pin_SetDigitalOutput() (_TRISA0 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA2 GPIO Pin which has a custom name of LED_G to High
 * @pre      The RA2 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define LED_G_SetHigh()          (_LATA2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA2 GPIO Pin which has a custom name of LED_G to Low
 * @pre      The RA2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_G_SetLow()           (_LATA2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA2 GPIO Pin which has a custom name of LED_G
 * @pre      The RA2 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_G_Toggle()           (_LATA2 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA2 GPIO Pin which has a custom name of LED_G
 * @param    none
 * @return   none  
 */
#define LED_G_GetValue()         _RA2

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA2 GPIO Pin which has a custom name of LED_G as Input
 * @param    none
 * @return   none  
 */
#define LED_G_SetDigitalInput()  (_TRISA2 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA2 GPIO Pin which has a custom name of LED_G as Output
 * @param    none
 * @return   none  
 */
#define LED_G_SetDigitalOutput() (_TRISA2 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA3 GPIO Pin which has a custom name of LED_B to High
 * @pre      The RA3 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define LED_B_SetHigh()          (_LATA3 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA3 GPIO Pin which has a custom name of LED_B to Low
 * @pre      The RA3 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_B_SetLow()           (_LATA3 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA3 GPIO Pin which has a custom name of LED_B
 * @pre      The RA3 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_B_Toggle()           (_LATA3 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA3 GPIO Pin which has a custom name of LED_B
 * @param    none
 * @return   none  
 */
#define LED_B_GetValue()         _RA3

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA3 GPIO Pin which has a custom name of LED_B as Input
 * @param    none
 * @return   none  
 */
#define LED_B_SetDigitalInput()  (_TRISA3 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA3 GPIO Pin which has a custom name of LED_B as Output
 * @param    none
 * @return   none  
 */
#define LED_B_SetDigitalOutput() (_TRISA3 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA4 GPIO Pin which has a custom name of LED_R to High
 * @pre      The RA4 must be set as Output Pin             
 * @param    none
 * @return   none  
 */
#define LED_R_SetHigh()          (_LATA4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Sets the RA4 GPIO Pin which has a custom name of LED_R to Low
 * @pre      The RA4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_R_SetLow()           (_LATA4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Toggles the RA4 GPIO Pin which has a custom name of LED_R
 * @pre      The RA4 must be set as Output Pin
 * @param    none
 * @return   none  
 */
#define LED_R_Toggle()           (_LATA4 ^= 1)

/**
 * @ingroup  pinsdriver
 * @brief    Reads the value of the RA4 GPIO Pin which has a custom name of LED_R
 * @param    none
 * @return   none  
 */
#define LED_R_GetValue()         _RA4

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA4 GPIO Pin which has a custom name of LED_R as Input
 * @param    none
 * @return   none  
 */
#define LED_R_SetDigitalInput()  (_TRISA4 = 1)

/**
 * @ingroup  pinsdriver
 * @brief    Configures the RA4 GPIO Pin which has a custom name of LED_R as Output
 * @param    none
 * @return   none  
 */
#define LED_R_SetDigitalOutput() (_TRISA4 = 0)

/**
 * @ingroup  pinsdriver
 * @brief    Initializes the PINS module
 * @param    none
 * @return   none  
 */
void PINS_Initialize(void);



#endif
