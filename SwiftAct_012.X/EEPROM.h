/* 
 * File:   EEPROM.h
 * Author: Abdelrahman Bakr
 *
 * Created on July 7, 2020, 11:25 AM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "I2C.h"

    
    
       
  /**************************************** 
  * Functions declaration                 *
  ****************************************/
    void   EEPROM_Init(void);
    void EEPROM_Write(uint8_t addr, uint8_t val);
    uint8_t EEPROM_Read(uint8_t addr);



#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

