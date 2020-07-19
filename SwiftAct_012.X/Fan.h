/* 
 * File:   Fan.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 2, 2020, 5:45 PM
 */

#ifndef FAN_H
#define	FAN_H

#ifdef	__cplusplus
extern "C" {
#endif

    
            #include <xc.h>
            #include  <stdint.h> 
            

     #define FAN_ENABLED    TRISCbits.TRISC2  
     #define FAN            PORTCbits.RC2  
   
  /**************************************** 
  * Functions declaration             *
  ****************************************/
    void Fan_Init(void); 
    void Fan_Start(void); 
    void Fan_Stop(void);

    



#ifdef	__cplusplus
}
#endif

#endif	/* FAN_H */

