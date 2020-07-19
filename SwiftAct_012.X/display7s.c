
#include <pic16f877a.h>

#include "display7s.h" 


 /**************************************** 
  * Functions implementation             *
  ****************************************/
/**
 * this Function Writes a number from 0 to 9 on the 7 seg display 
 * @param Num
 */
void  Sev_Seg_Write( uint16_t Num)
{
  switch(Num)
  {
    case 0:
      SEVEN_SEG_DATA =  0x3F;
      break ; 
    case 1:
      SEVEN_SEG_DATA =  0x06;
      break ; 
    case 2:
      SEVEN_SEG_DATA =  0x5B;
      break ; 
    case 3:
      SEVEN_SEG_DATA =  0x4F;
      break ; 
    case 4:
      SEVEN_SEG_DATA =  0x66;
      break ; 
    case 5:
      SEVEN_SEG_DATA =  0x6D;
      break ; 
    case 6:
      SEVEN_SEG_DATA =  0x7D;
      break ; 
    case 7:
      SEVEN_SEG_DATA =  0x07;
            break ; 

    case 8:
      SEVEN_SEG_DATA =  0x7F;
            break ; 

    case 9:
      SEVEN_SEG_DATA =  0x6F;
          break ; 

    default:
      break;
  }
}

/**
 *  this function choose which Display to enable 
 * @param Disp
 */
void Sev_Seg_Enable(unsigned char Disp )
{   
    switch (Disp){
        case DISP1 :
             SEVEN_SEG1_ENABLE  = ENABLE  ;  
             SEVEN_SEG2_ENABLE  = DISABLE   ;
             break ; 
        case DISP2:
             SEVEN_SEG1_ENABLE  = DISABLE     ;  
             SEVEN_SEG2_ENABLE  = ENABLE   ;
             break ; 
        default:
             break;
    }

}
/*
 * this function disable the 7 segments display 
 */
 void Sev_Seg_Disable(void){
     
                SEVEN_SEG1_ENABLE  = DISABLE    ;  
                SEVEN_SEG2_ENABLE  = DISABLE   ;
 }
void Sev_Seg_Init(void )
{   
        /// these two pins are used for enabling and disabling 7Seg displays
       ///  Set the direction as output 
      TRISAbits.TRISA4  = 0 ;  
      TRISAbits.TRISA3  = 0 ; 
      /// Set the Direction as output
      SEVEN_SEG_DIR = 0x00 ;   
}

void Sev_Seg_Write_99( uint16_t Num){
    
    unsigned char Units ,Tens ; 
    Units = Num % 10 ; /// get the units digit 
    Tens = Num / 10 ; /// get tens digit 
    
    Sev_Seg_Enable(DISP2);   /// enable tens digit  display  
    Sev_Seg_Write(Tens);    /// write tens digit 
            __delay_ms(5);
    Sev_Seg_Enable(DISP1);  /// enable units digit display 
    Sev_Seg_Write(Units);  /// write units digit 
            __delay_ms(5);
    
}