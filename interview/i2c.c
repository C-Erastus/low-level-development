/* Implementing I2C communicaton in an embedded system(Arduino) */
#include <Wire.h>

void setup(){
	Wire.begin(); /* Initialize I2C as master */
}

void loop(){
	Wire.beginTransmission(0x50); /*Address of the I2C device */
	Wire.write(0x00); /* Data to send */
	Wire.endTransmission();
	delay(1000);
}

/* function to initialize the I2c interface on a Raspberry PI using  the 'wiringPI' library */
int i2c_init(int device_address)
{
	int fd = wiringPiI2CSetup(device_address);
	if (fd== -1){
		perror("Failed to initialize I2C");
		return -1; 
	}
	return fd; 
}

/* A function to read a byte from an I2C device */
#include <wiringPiI2C.h>
int i2c_read_byte(int fd, uint8_t reg)
{
	return wiringPiI2CReadingReg8(fd, reg); 
}

/* Afuncton to write a byte on an I2C device */
int i2c_write_byte(int fd, uint8_t reg, uint8_t data)
{
	return wiringPiI2CWriteReg8(fd, reg, data);
}

/* A function to read a block of data from an I2C device using repeated start conditons */
#include <wiringPiI2C.h>
#include <stdio.h>

int i2c_read_block(int fd, uint8_t reg, uint8_t *buffer, int length)
{
	int result = wiringPiI2CWrite(fd, reg); 
	if (result == -1){
		perror("Failed to write register address"); 
	}

	for  (int i = 0; i < length; i++){
		buffer[i] = wiringPiI2CRead(fd);
		if (buffer[i] == -1){
			perror("Failed to read data");
			return -1; 
		}
	}
	return 0; 
}