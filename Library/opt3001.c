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

#include "opt3001.h"
extern I2C_HandleTypeDef hi2c1;


static uint8_t device_addr= OPT3001_ADDR1;
static uint16_t config_data= 0xCE10;        //The sensor works in continuous operation mode by default.


void opt3001_writedata(uint8_t device_addr, uint8_t register_addr, uint16_t data){

	 uint8_t buffer[3];
	 buffer[0] = register_addr;
	 buffer[1] = (data)>>8;
	 buffer[2] = (data)& 0x00FF;
	 HAL_I2C_Master_Transmit(&hi2c1, device_addr<<1, buffer, 3, 50);
 }


uint16_t opt3001_readdata(){

	uint8_t readbuffer[2];
	uint16_t received_data;
	HAL_I2C_Master_Receive(&hi2c1, device_addr<<1, readbuffer, 2, 50);
	received_data = ((readbuffer[0] << 8) | readbuffer[1]);
	
	return received_data;
}

uint8_t opt3001_init(){

	if (HAL_I2C_IsDeviceReady(&hi2c1, device_addr<<1, 1, 20000) != HAL_OK){
		/* Return false */
		return 0;
	}

	opt3001_writedata(device_addr, OPT3001_ConfigReg, config_data);
	return 1;
}


float calculate_lux(){
	
	uint16_t iExponent, iMantissa;
    float final_lux;
    uint16_t rawlux;

    opt3001_writedata(device_addr, OPT3001_ResultReg, 0x00);
    HAL_Delay(50);
    rawlux = opt3001_readdata();
    iMantissa = rawlux & 0x0FFF;
    iExponent = (rawlux & 0xF000) >> 12;
    final_lux = iMantissa * (0.01 * powf(2, iExponent));
	
    return final_lux;
}

uint16_t read_devid(){

	uint16_t received_data;
    opt3001_writedata(device_addr, OPT3001_DeviceID, 0x00);
    HAL_Delay(50);
    received_data = opt3001_readdata();

	return received_data;

}

uint16_t read_manufacturer_id(){

	uint16_t received_data;
    opt3001_writedata(device_addr, OPT3001_ManuID, 0x00);
    HAL_Delay(50);
    received_data = opt3001_readdata();

	return received_data;
}
