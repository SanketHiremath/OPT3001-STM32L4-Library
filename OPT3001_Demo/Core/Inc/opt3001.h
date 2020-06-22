/**
 * Author:  Sanket Hiremath
   ----------------------------------------------------------------------
   	Copyright (C) Sanket Hiremath, 2020

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

   ----------------------------------------------------------------------
 */
#include "stdint.h"
#include "math.h"
#include "stm32l4xx_hal.h"

#ifndef OPT3001_H_
#define OPT3001_H_

#ifndef STM32L4xx_HAL_I2C_H
#define STM32L4xx_HAL_I2C_H
#endif


#define OPT3001_ADDR1 	0x44        //GND (Default)
#define OPT3001_ADDR2	0x45        //VDD
#define OPT3001_ADDR3	0x46        //SDA
#define OPT3001_ADDR4	0x47		//SCL

#define OPT3001_ConfigReg	0x01
#define OPT3001_ResultReg	0x00
#define OPT3001_SetLow	    0x02
#define OPT3001_SetHigh     0x03
#define OPT3001_ManuID      0x7E
#define OPT3001_DeviceID    0x7F



void opt3001_writedata(uint8_t device_addr, uint8_t register_addr, uint16_t data ); //This function is used to write data to different registers.

uint16_t opt3001_readdata();         //This function is used to read raw data from different registers.

uint8_t opt3001_init();              //Initialize the sensor

float calculate_lux();               //get the ambient light level value from the sensor(in Lux)

uint16_t read_devid();              //Read the device id

uint16_t read_manufacturer_id();    //Read the manufacturer id




#endif /* OPT3001_H_ */
