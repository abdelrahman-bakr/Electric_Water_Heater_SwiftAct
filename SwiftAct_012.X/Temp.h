/* 
 * File:   Temp.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 2, 2020, 4:47 PM
 */

#ifndef TEMP_H
#define	TEMP_H

#ifdef	__cplusplus
extern "C" {
#endif

      #include <xc.h>
      #include  <stdint.h> 
      #define _XTAL_FREQ 8000000
  
    
   
      #define CONVERSION_RATIO 0.489     ///   5v / 1024   "resolution "
  /**************************************** 
  * Functions declaration             *
  ****************************************/
     
       void      Temp_Sensor_ADC_Init(void) ; 
       uint16_t  Temp_Sensor_ADC_Read(void) ; 
       void      Temp_Sensor_ADC_Init_Interrupt(void);
       void      ADC_Start_Conversoin(void);

#ifdef	__cplusplus
}
#endif

#endif	/* TEMP_H */

