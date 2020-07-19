/* 
 * File:   Heater.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 2, 2020, 6:18 PM
 */

#ifndef HEATER_H
#define	HEATER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
     #include <xc.h>
     #include  <stdint.h> 
    

     #define HEATER_ENABLED    TRISCbits.TRISC5  
     #define HEATER            PORTCbits.RC5  
   
  /**************************************** 
  * Functions declaration             *
  ****************************************/
    void Heater_Init(void); 
    void Heater_Start(void); 
    void Heater_Stop(void);




#ifdef	__cplusplus
}
#endif

#endif	/* HEATER_H */

