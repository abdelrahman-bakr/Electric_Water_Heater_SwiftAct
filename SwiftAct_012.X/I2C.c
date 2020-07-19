
#include "I2C.h"



void I2C_Init(uint8_t feq_K)
{
    ///Set SDA and SCL pins as input pins
     TRISCbits.TRISC3 = 1;  
     TRISCbits.TRISC4 = 1; 
    

  SSPCON  = 0b00101000;    
  SSPCON2 = 0b00000000;    
  SSPADD = (_XTAL_FREQ/(4*feq_K*100))-1; //Setting Clock Speed  
  SSPSTAT = 0b00000000;    
             
}
void I2C_Hold()
{
    while (   (SSPCON2 & 0b00011111)    ||    (SSPSTAT & 0b00000100)   ) ; //check the this on registers to make sure the IIC is not in progress
}
void I2C_Start(void)
{
    I2C_Hold();  //Hold the program is I2C is busy 
      SSPCON2bits.SEN = 1 ;   //Begin IIC pg85/234
  
}
void I2C_Stop(void)
{
      I2C_Hold(); //Hold the program is I2C is busy 
      SSPCON2bits.PEN = 1 ; 
}
void I2C_Repeated_Start(void)
{
          I2C_Hold(); //Hold the program is I2C is busy 

  SSPCON2bits.RSEN = 1 ; 
  
}
void I2C_Write_Byte(uint8_t  val)
{
   
    I2C_Hold(); //Hold the program is I2C is busy
    SSPBUF = val ; /// Load the data on the buffer 
 
}
uint8_t Ack_Receive(void){
    
    while (SSPCON2bits.ACKSTAT == 1 ) ;
    return ACK_RECIVED ;
}
 uint8_t I2C_Read_Byte(uint8_t ack)
{
     uint8_t incoming ; 
     
     I2C_Hold();
     SSPCON2bits.RCEN =1 ;
     
     I2C_Hold();
     incoming = SSPBUF;      //get the data saved in SSPBUF
     
     I2C_Hold();
     ACKDT = (ack) ? 0 : 1 ;    //check if ack bit received 
     ACKEN = 1;                 //pg 85/234
     return incoming;
}