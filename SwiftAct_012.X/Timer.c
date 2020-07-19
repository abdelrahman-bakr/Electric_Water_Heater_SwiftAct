#include <pic16f877a.h>
#include "Timer.h" 


void TMR1_Init(void){

    /** Pre scaler is 1/8  ***/
    T1CONbits.T1CKPS0 = 1 ; 
    T1CONbits.T1CKPS1 = 1 ; 
    
    
    /** Timer 1 clock source is internal **/
      T1CONbits.TMR1CS = 0 ; 
    /** Timer 1 osc is off to elimintae power drain  **/
      T1CONbits.T1OSCEN = 0 ;
      /** Timer 1 no sync with external clock **/
      T1CONbits.nT1SYNC = 1 ; 
      
        /**Timer is on  **/
      T1CONbits.TMR1ON = 1 ; 
      
      /** Enable interrupt of timer 1 **/
      PIE1bits.TMR1IE =  1 ; 
      
      /** Load the timer value to get 250 ms interrupt **/
      TMR1L = 0xDC; 
      TMR1H = 0x0B ;
     
}

void TMR0_Init(void){
    
    OPTION_REGbits.T0SE =    0 ;    //// edge select
    OPTION_REGbits.T0CS =    0 ;  /// clock select 
    OPTION_REGbits.PSA  =    0 ;  //// enable Pre scalar for timer 0 
    OPTION_REGbits.PS0  =    1 ;    /// choosing 1:64 pre scalar 
    OPTION_REGbits.PS1  =    0 ;    /// choosing 1:64 pre scalar 
    OPTION_REGbits.PS2  =    1 ;    /// choosing 1:64 pre scalar 
    INTCONbits.T0IE     =    1 ;  /// Timer 0 interrupt is on 
    
    TMR0 = 0x83 ;    
    
}