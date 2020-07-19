/* 
 * File:   Leds.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 7, 2020, 12:24 AM
 */

#ifndef LEDS_H
#define	LEDS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
       #include <xc.h>
   

#define HEATING_ELEMENT_LED_DIR  TRISBbits.TRISB7  
#define HEATING_ELEMENT_LED_PIN  PORTBbits.RB7  

  /**************************************** 
  * Functions declaration             *
  ****************************************/
    void Heating_LED_Init(void) ; 
    void Heating_LED_On(void) ; 
    void Heating_LED_Off(void) ; 
    void Heating_LED_Toggle(void) ;

#ifdef	__cplusplus
}
#endif

#endif	/* LEDS_H */

