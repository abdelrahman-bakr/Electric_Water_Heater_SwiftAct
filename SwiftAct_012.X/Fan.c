
#include "Fan.h" 

void Fan_Init(void){
    FAN_ENABLED =  0 ;  //// Set the direction as output 
}
    void Fan_Start(void){ 
        FAN = 1 ;  //// start the Fan
    }
    
    void Fan_Stop(void){
    FAN = 0 ;       //// Stop the fan 
    }

