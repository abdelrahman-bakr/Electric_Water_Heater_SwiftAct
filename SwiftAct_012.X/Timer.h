/* 
 * File:   Timer.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 6, 2020, 8:02 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

    
      #include <xc.h>
      #include  <stdint.h> 

      
      
  /**************************************** 
  * Functions declaration             *
  ****************************************/
       void TMR1_Init(void); 
       void TMR0_Init(void);



#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

