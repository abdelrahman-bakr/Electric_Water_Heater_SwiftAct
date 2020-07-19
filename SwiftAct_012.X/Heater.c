

#include "Heater.h"

   void Heater_Init(void){
   
       HEATER_ENABLED = 0 ; /// set the direciton to output 
   }
    void Heater_Start(void){
        HEATER =  1 ;       /// start the heater 
        
    }
    void Heater_Stop(void){
        HEATER = 0 ;        //// stop the heater 
    }
