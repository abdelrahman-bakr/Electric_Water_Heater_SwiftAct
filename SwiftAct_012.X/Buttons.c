

#include <pic16f877a.h>
#include"Buttons.h" 

 void Buttons_Init(void) {
        
     /// Set the buttons pins as Input 
          TRISBbits.TRISB0 = 1 ; 
          TRISBbits.TRISB1 = 1 ;
          TRISBbits.TRISB2 = 1 ; 
          
 }
 void ON_Button_EXTI_Init(){
     
     GIE=1;          //Enable Global Interrupt
     PEIE=1;         //Enable the Peripheral Interrupt
     OPTION_REGbits.INTEDG =  0 ;  /// interrupt is issued on falling edge 
     OPTION_REGbits.nRBPU = 0 ;  //// PIN B0 Pull up 
     INTE = 1;       //Enable RB0 as external Interrupt pin 
     
 }
    
  unsigned char Up_Pressed(void){
      if(UP == 0 ){
          __delay_ms(DEBOUNCING_INTERVAL); /// wait for de bouncing 
          
          if(UP == 0 ){
              return PRESSED ; 
          }
          else{
              return NOT_PRESSED ; 
          }
      }
      else{
              return NOT_PRESSED ; 
          }
  }
    unsigned char Down_Pressed(void){
     if(DOWN == 0 ){
          __delay_ms(DEBOUNCING_INTERVAL); /// wait for de bouncing 
          
                if(DOWN == 0 ){
                    return PRESSED ; 
                }
                else{
                    return NOT_PRESSED ; 
                }
      }
     else{
              return NOT_PRESSED ; 
          }
    }  
    unsigned char ON_OFF_Pressed(void){
        if(ON_OFF == 0 )
        {
          __delay_ms(DEBOUNCING_INTERVAL); /// wait for de bouncing 

                if(ON_OFF == 0 ){
                    return PRESSED ; 
                }
                else{
                    return NOT_PRESSED ; 
                }
        }
         else
        {
              return NOT_PRESSED ; 
        }
    }  