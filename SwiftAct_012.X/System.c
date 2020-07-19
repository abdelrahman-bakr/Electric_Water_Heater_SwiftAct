/**
 * this file Contain system functions 
 * and States functions 
 */
#include "System.h"


void Task_OFF_State(void){
    
                   Sev_Seg_Disable() ;  //// Disable the 7Seg Display
                   Fan_Stop();          //// Stop the fan 
                   Heater_Stop();       //// Stop the Heating Element 
                   SLEEP();             //// Go to sleep mode to save power 
                        

}
void Task_ON_State(void){
    
                    /**
                     * this flag Temp_Measure_indication is set each 100 ms 
                     *  Temp is measured each 100 ms as required 
                     */
                    if(Temp_Measure_indication == 1){
                        
                            Actual_Temp = Temp_Sensor_ADC_Read();     /// Read actual Temp  each 100 ms 
                            Add_New_Temp(Temp_Measurments,Actual_Temp); /// add the new Temp to the array 
                            Actual_Temp_Avg = Calc_Temp_Avg(Temp_Measurments); /// calculate the new average 
                            Temp_Measure_indication = 0 ;               /// reset the flag to 0 
                    }
                    
                    Sev_Seg_Write_99(Actual_Temp);           /// Display the Temp on 7 seg Display
                    Adjust_Temp();                          /// turn on fan or heater to adjust the Temp 
                
                     if(Up_Pressed() == PRESSED || Down_Pressed() == PRESSED) //// check for up  or down button presses to enter Change Temp mode 
                       {
                      Sev_Seg_Disable();    /// Disable 7 seg display 
                      SettingMode_counter = 0 ; //// set the SettingMode Counter to 0  "to indicate the last press "
                      Current_State = CHANGE_TEMP_STATE ;  /// Enter Set Temp mode 
                   
                       }
}
void Task_ChangeTemp_State(void){
                /** Stop heating or cooling while the user is setting the temp  **/
                      Fan_Stop();
                      Heater_Stop();
                      Heating_LED_Off(); 
                      
                      /** Toggling Seven segments to indicate Temp setting mode **/
                      if(Toggle_indication == 0 ){
                          Sev_Seg_Write_99(Desired_Temp); 
                      }else{
                          Sev_Seg_Disable(); 
                      }
                      /** check for up/down button presses **/
                      if( ( Up_Pressed() == PRESSED ) && (Desired_Temp < MAX_TEMP) )
                      {
                          SettingMode_counter = 0 ; 
                          Desired_Temp +=5 ;  
                      }
                      if ( (Down_Pressed() == PRESSED) && (Desired_Temp > MIN_TEMP) )
                      {
                          SettingMode_counter = 0 ;
                         Desired_Temp -=5 ;  
                      }
                      else
                      {
                          // do nothing 
                      }
                      /** saving the desired temp once set  **/
                      EEPROM_Write(0x00,Desired_Temp);
}

void Sys_Init(){
     
           /// init all modules 
          /// Set initial Temp  & save it to EEPROM 
         /// fill the 10 readings in the array with first measure 
        /// Set initial state 
       Sev_Seg_Init(); 
       Buttons_Init();
       ON_Button_EXTI_Init();
       Fan_Init(); 
       Heater_Init(); 
       Temp_Sensor_ADC_Init();
       TMR1_Init();
       TMR0_Init();
       Heating_LED_Init();
       EEPROM_Init();
       Temp_Array_Init();
       Current_State = OFF_STATE ;
       Desired_Temp = INITIAL_DESIRED_TEMP; 
       EEPROM_Write(0x00 ,INITIAL_DESIRED_TEMP ); 
       

}
/**
 * this function Adjust the temperature 
 * by Turning off and on cooling element or Heating element 
 * based on the average Temp of the last 10 measurments 
 */
void Adjust_Temp(void){
    
   /// Temperature is Adjusted based on The average  of The Last Ten Measurements 
    
    if( (Desired_Temp < Actual_Temp_Avg + MARGIN_TEMP ) && (Desired_Temp > Actual_Temp_Avg - MARGIN_TEMP )  )
    {
         Fan_Stop(); 
         Heater_Stop() ;
         Heating_LED_Off(); 
    }
    else if( Desired_Temp > Actual_Temp_Avg + MARGIN_TEMP ){
        Fan_Stop(); 
        Heater_Start(); 
        if(Toggle_indication == 0 ){
        Heating_LED_Toggle(); 
        }
       
        
    }
    else if ( Desired_Temp < Actual_Temp_Avg - MARGIN_TEMP ){
         Fan_Start(); 
         Heater_Stop() ;
         Heating_LED_On(); 
    
    }
   
  
         
    
}

/**
 *  This Function  Adds  a new element to the array and shift the elements like a Queue 
 * @param Array
 * @param Newest_Value
 */
void Add_New_Temp(uint16_t* Array,uint16_t Newest_Value){

    
    for(uint8_t element = NUM_OF_TEMP_MEASUREMENTS -1 ; element > 0 ; element -- ){
        Array[element] = Array[element -1]; 
    }
    Array[0] = Newest_Value ;
} 
/**
 * 
 * @param Array
 * @return  the average of the array 
 * 
 */
uint16_t Calc_Temp_Avg(uint16_t * Array){
    
    uint16_t Sum = 0 ; 
     uint16_t Avg  ;
     
    for(uint8_t element = 0 ; element < NUM_OF_TEMP_MEASUREMENTS ; element ++ ){
        Sum = Sum + Array[element] ; 
    }
    Avg = (uint16_t) Sum/NUM_OF_TEMP_MEASUREMENTS ; 
    return Avg; 
}
/**
 * This Function init the Array by filling it with the same first measurment 
 * and calculates the Average for the first time 
 */
void Temp_Array_Init(void){

        /**
        * fill the array with the first Temp measured 
        */
       
        First_Temp_Measured  = Temp_Sensor_ADC_Read(); 
        
       for(uint8_t i =0 ; i<NUM_OF_TEMP_MEASUREMENTS ; i++)
       {
          Temp_Measurments[i] = First_Temp_Measured ; 
       }
        /**
         * Calculate the Average for the first time 
         */
         Actual_Temp_Avg = Calc_Temp_Avg(Temp_Measurments);
}
/**
 * For Disabling and enabling interrupts before entering critical sections  if needed 
 * 
 */
void Disable_Interrupt(void){
     PEIE=0;         //Disable the Peripheral Interrupt

}
void Enable_Interrupt(void){
     PEIE=1;         //Enable the Peripheral Interrupt

}