/*
 * File:   Electric_Water_Heater.c
 * Author: Abdelrahman Bakr 
 *
 * Created on June 29, 2020, 3:32 PM
 */

/**

 */

// PIC16F877A Configuration Bit Settings
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



#include <xc.h>
#include"System.h"



void __interrupt() System_Interrupts()
{
         /**
          * This external interrupt is  pin B0
          * it is triggered when On_Off button is pressed 
          * it is used to switch the system states between on or Off   
          **/
        if (INTF==1) //External Interrupt detected
        {
            if(Current_State == OFF_STATE)
            {
                /** Go back to on State **/
                Current_State = ON_STATE ; 
                /** if the Heater is turned off then on the Temp should be retrieved from the EEPROM **/
                Desired_Temp = EEPROM_Read(0x00); 
            }
            else if (Current_State == ON_STATE || Current_State == CHANGE_TEMP_STATE)
            {
                /** Go to off State  **/
                Current_State = OFF_STATE ; 
            }    
           INTF = 0;          // clear the interrupt flag after done with it 
        }
        /**********************************************************/
        /**
         * this is Timer 1  over flow interrupt 
         * it is triggered every 250 ms 
         * each 250 ms (SettingMode_counter) is incremented  
         * after 4 increments 1 Sec is passed so Toggling indicator is flipped 
         * after 20 increments ( 5 * 4 ) 5 Sec are passed so exit Setting mode 
         * checking for On state or Change Temp state because we need toggeling in both states 
         * in On state toggle indicator is needed for Heater Led toggling
         * in Change Temp state toggle indicator is needed for Seven Segment Display toggling
         **/
        if (PIR1bits.TMR1IF ==1){
            
            if( ( Current_State == CHANGE_TEMP_STATE) || ( Current_State == ON_STATE) ){
                
                SettingMode_counter ++;
                
                if(SettingMode_counter % 4  == 0 ){
                    Toggle_indication ^= 1 ;  ///to change the toggling  indicator each 1 Sec 
                }
                
                if(SettingMode_counter > 20 ){
                    Current_State = ON_STATE ;    /// exiting setting mode after 5 seconds  
                }
            }
          
              /**  re Load the timer value to get 250 ms interrupt **/
                TMR1L = 0xDC; 
                TMR1H = 0x0B ; 
                PIR1bits.TMR1IF = 0;          // clear the  timer interrupt flag 
        }
        /**********************************************************/
        /**
         * this interrupt for Timer 0 
         * it is used to count 100 ms delay 
         * the intterupt is issued each 4 ms 
         * so we increment a counter for 25 times to indicate 100 ms delay 
         * each 100 ms Temp is measured 
         **/
        
   
        if (INTCONbits.T0IF ==1){
            /// increment the counter each 4 ms 
            Temp_Measure_counter ++ ;  
            /// check if it equals 25 which means 100 ms is passed  
            if(Temp_Measure_counter >= 25 ){
                Temp_Measure_counter = 0 ; /// reset the counter to 0 
                Temp_Measure_indication = 1 ; /// set the indication flag to true 
            }
            TMR0 = 0x83 ;  /// Reload the timer  131 decimal 
            INTCONbits.T0IF = 0  ;          
        }
  
        /*******************************************************/
        
        
}




void main(void) {
    
       Sys_Init();     
       
      while(1) {
           
        
            switch (Current_State) {
               
                case OFF_STATE: 
                    Task_OFF_State();
                   break;
            /*****************************************************************/              
                case ON_STATE: 
                   Task_ON_State();
                   break;   
            /*****************************************************************/         
                  case CHANGE_TEMP_STATE: 
                      Task_ChangeTemp_State();
                   break; 
            /*****************************************************************/    
                   
           }
}
}