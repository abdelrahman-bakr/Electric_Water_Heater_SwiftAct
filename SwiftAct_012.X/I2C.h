/* 
 * File:   I2C.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 7, 2020, 11:31 AM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#include<xc.h>
#include <stdint.h>
 #define _XTAL_FREQ 8000000


#define SCK   PORTCbits.RC3
#define SDA   PORTCbits.RC4
#define SDA_PIN_DIR  TRISCbits.TRISC4
#define SCK_PIN_DIR  TRISCbits.TRISC3
    
 #define ACK_RECIVED 0 
 #define ACK_NOT_RECIVED 1    
    
  /**************************************** 
  * Functions declaration             *
  ****************************************/
void I2C_Init(uint8_t feq_K);
void I2C_Hold(void);
void I2C_Start(void);
void I2C_Repeated_Start(void);
void I2C_Stop(void);
void I2C_Write_Byte(uint8_t val);
uint8_t I2C_Read_Byte(uint8_t ack);
uint8_t Ack_Receive(void);



#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

