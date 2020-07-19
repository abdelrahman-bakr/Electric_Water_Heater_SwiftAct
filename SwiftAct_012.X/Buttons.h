/* 
 * File:   Buttons.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 2, 2020, 4:05 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
     #include <xc.h>
     #define _XTAL_FREQ 8000000
     #include  <stdint.h> 



#define ON_OFF       RB0 
#define UP           RB2 
#define DOWN         RB1
    
 #define PRESSED             1 
 #define NOT_PRESSED         0 

#define DEBOUNCING_INTERVAL  75      /// this parameter is used to eliminate  debouncing of buttons  it is set to 75 ms 
    
  

  /**************************************** 
  * Functions declaration             *
  ****************************************/
    void Buttons_Init(void) ; 
    unsigned char Up_Pressed(void);  
    unsigned char Down_Pressed(void);  
    unsigned char ON_OFF_Pressed(void);  
    void ON_Button_EXTI_Init(void);
     
    


#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */

