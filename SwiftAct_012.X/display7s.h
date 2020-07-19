/* 
 * File:   display7s.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 1, 2020, 3:48 PM
 */

#ifndef DISPLAY7S_H
#define	DISPLAY7S_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <xc.h>
    #include  <stdint.h> 
    #define _XTAL_FREQ 8000000


#define ENABLE  1 
#define DISABLE 0 
    
#define DISP1 1 
#define DISP2 2 
   
#define SEVEN_SEG_DATA       PORTD 
#define SEVEN_SEG_DIR        TRISD 
#define SEVEN_SEG1_ENABLE    RA4
#define SEVEN_SEG2_ENABLE    RA3
#define SEVEN_SEG1_ON_OFF    TRISAbits.TRISA2
#define SEVEN_SEG_ON         0 
#define SEVEN_SEG_OFF        1     
    
  /**************************************** 
  * Functions declaration             *
  ****************************************/

    
void Sev_Seg_Write( uint16_t Num );
void Sev_Seg_Enable(unsigned char Disp ); 
void Sev_Seg_Disable(void);
void Sev_Seg_Init(void );
void Sev_Seg_Write_99( uint16_t Num); 

#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY7S_H */

