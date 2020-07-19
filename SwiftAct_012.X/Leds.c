
#include "Leds.h"

  void Heating_LED_Init(void) { 
      HEATING_ELEMENT_LED_DIR =  0 ;  /// Led pin direction is output 
      HEATING_ELEMENT_LED_PIN = 0 ;  /// Led is initally  Off 
  }
    void Heating_LED_On(void) {
        
        HEATING_ELEMENT_LED_PIN = 1 ;   ///  heating element Led is on
    }
    void Heating_LED_Off(void) {
        
        HEATING_ELEMENT_LED_PIN = 0 ;  ///  heating element Led is off
        
    } 
    void Heating_LED_Toggle(void) {
        
        HEATING_ELEMENT_LED_PIN ^= 1 ;  ///  heating element Led toggles 
        
    } 

