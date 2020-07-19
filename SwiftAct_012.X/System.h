/* 
 * File:   System.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 3, 2020, 4:38 PM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <xc.h>
    #include  <stdint.h> 
    #include "Sys_Cfg.h"
    #include "Temp.h"
    #include "display7s.h"
    #include "Buttons.h" 
    #include "Fan.h"
    #include "Heater.h"
    #include "Timer.h" 
    #include "Leds.h"
    #include "EEPROM.h"

    #define OFF_STATE 0 
    #define ON_STATE  1 
    #define CHANGE_TEMP_STATE 2  

  /**************************************** 
  * Functions declaration             *
  ****************************************/
  void Sys_Init(void); 
  void Adjust_Temp(void); 
  
  
  void Add_New_Temp(uint16_t* Array,uint16_t Newest_Value);
  uint16_t Calc_Temp_Avg(uint16_t * Array);  
  void  Temp_Array_Init(void);
  
  void Disable_Interrupt(void);
  void Enable_Interrupt(void);
  
  /***Task Function Declaration **/
  void Task_OFF_State(void);
  void Task_ON_State(void);
  void Task_ChangeTemp_State(void);
/********** GLOBAL VARIABLES   ************/
  uint16_t Desired_Temp ;
  uint16_t Actual_Temp ;    
    
  volatile  uint8_t   Current_State;  
  volatile  uint8_t SettingMode_counter ;
  volatile  uint8_t Toggle_indication = 0 ; 
  
  
  volatile  uint8_t Temp_Measure_counter = 0  ; 
  volatile   uint8_t Temp_Measure_indication = 1 ;
  
  uint16_t Temp_Measurments[NUM_OF_TEMP_MEASUREMENTS]; 
  uint16_t First_Temp_Measured ; 
  uint16_t  Actual_Temp_Avg ;
  

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

