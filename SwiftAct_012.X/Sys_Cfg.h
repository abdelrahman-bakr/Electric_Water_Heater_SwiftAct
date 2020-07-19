/* 
 * File:   Sys_Cfg.h
 * Author: Abdelrahman Bakr 
 *
 * Created on July 12, 2020, 4:31 PM
 */

#ifndef SYS_CFG_H
#define	SYS_CFG_H


     //// this parameter is to configure the system Clock  
        /// it is redefined in other files too so to change it we have to change it in all files 
     #define _XTAL_FREQ 8000000
    
    
    ///  Parameters to Configure Temperature 
    #define MARGIN_TEMP 1   //// this parameter is used to determine the margin between actual temp and desired temp 

    #define MAX_TEMP 75    //// this parameter is used to set the max desired temp 
    #define MIN_TEMP 35    //// this parameter is used to set the min desired temp

    #define INITIAL_DESIRED_TEMP 60  //// this parameter is used to set the initial desired temp 
    
     #define NUM_OF_TEMP_MEASUREMENTS 10  /// this parameter to choose how many reading to be averaged 
     


#endif	/* SYS_CFG_H */

