
#include <pic16f877a.h>

#include "Temp.h"
#include "System.h"


  void Temp_Sensor_ADC_Init(void) {
      
        //// enable ADC module 
        ADCON0bits.ADON = 1; 
        //// conversion clock select bit 
        ADCON0bits.ADCS0 = 0; 
        ADCON0bits.ADCS1 = 0; 
        ADCON1bits.ADCS2 = 0;  
        //// analog channel select 
        ADCON0bits.CHS0 = 0 ;
        ADCON0bits.CHS1 = 1 ;
        ADCON0bits.CHS2 = 0 ;
        /// result is Right justified 
        ADCON1bits.ADFM = 1 ;   
        ///Port configuration control 
        ADCON1bits.PCFG0 = 0 ;
        ADCON1bits.PCFG1 = 0 ;
        ADCON1bits.PCFG2 = 0 ;
        ADCON1bits.PCFG3 = 0 ;
        
            /***   ****/
        /// A2 pin is input pin    
        TRISAbits.TRISA2 = 1 ; 

  }
  
   uint16_t  Temp_Sensor_ADC_Read(void){
      
      uint16_t result ; 
  
             __delay_us(30);    
            /* start analog to digital conversion */
           
             ADCON0bits.GO_nDONE = 1 ; 
            /* wait for conversion to end */
            
            while( ADCON0bits.GO_nDONE == 1  );
         
            /* get the result */
             
            result =  ( (ADRESH<<8) | ADRESL  ) *  CONVERSION_RATIO  ; 
            
            return result ; 
           
  }
   
   /*** unused**/
  void  Temp_Sensor_ADC_Init_Interrupt(void){
  
      
        ADCON0bits.ADON = 1; 
        
        ADCON0bits.ADCS0 = 0; 
        ADCON0bits.ADCS1 = 1; 
        ADCON1bits.ADCS2 = 0;  
        
        ADCON0bits.CHS0 = 0 ;
        ADCON0bits.CHS1 = 1 ;
        ADCON0bits.CHS2 = 0 ;
        
        ADCON1bits.ADFM = 1 ;   /// result is Right justified 
        
        ADCON1bits.PCFG0 = 0 ;
        ADCON1bits.PCFG1 = 0 ;
        ADCON1bits.PCFG2 = 0 ;
        ADCON1bits.PCFG3 = 0 ;
        
            /***   ****/
           
                 TRISAbits.TRISA2 = 1 ; 
                PIR1bits.ADIF   = 0 ; 
                PIE1bits.ADIE   = 1 ; 
                INTCONbits.PEIE = 1 ; 
                INTCONbits.GIE  = 1 ; 
                ADC_Start_Conversoin();
             
  
  }
      
  void ADC_Start_Conversoin(void){
      /* start analog to digital conversion */
           
             ADCON0bits.GO_nDONE = 1 ; 
  }