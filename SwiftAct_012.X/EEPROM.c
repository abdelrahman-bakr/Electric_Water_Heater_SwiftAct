#include "EEPROM.h"


 void   EEPROM_Init(void){
 I2C_Init(100); //Initialize I2C Master with 100KHz clock 
 }

 
 uint8_t EEPROM_Read(uint8_t Address)
{
    I2C_Start();            /// send start condition 
    I2C_Write_Byte(0xA0);   /// send EEPROM address to indicate Writing to the Memory 
    
    I2C_Write_Byte(Address);  //// Send the Address that will be read from 
    
    I2C_Start();            //// send a start condition again 
    I2C_Write_Byte(0xA1);   //// send EEPROM Address to indicate Reading from the Memory 
    
 return   I2C_Read_Byte(1); //// read the byte in the specified address and return it 
  
}

void EEPROM_Write(uint8_t  Address, uint8_t  Value)
{
    I2C_Start();        /// send start condition 
    I2C_Write_Byte(0xA0);  /// send EEPROM address to indicate Writing to the Memory 
    
    I2C_Write_Byte(Address);   //// Send the Address that will be written to 
    
    I2C_Write_Byte(Value);    //// send the value to be written in the specified address 
    I2C_Stop();              /// Send a  stop condition 
       
   
}