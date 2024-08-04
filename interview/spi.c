#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

/* Function to initialzie the SPI interface on a Raspberry PI using the 'spidev' library */
int spi_init(const char *dev, uint8_t mode, uint32_t speed){
	int fd = open(device, O_R);
	if(fd < 0){
		perror("Failed to open SPI deve");
		return -1; 
	}

	if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0){
		perror("failed to set SPI mode");
		close(fd); 
		return -1;
	}

	if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed) < 0){
		perror("Failed to set SPI speed");
		close(fd); 
		return -1; 
	}

	return fd; 
}

/* SPI communication protocol in an embedded system to read data from an ADC */
unit16_t read_adc(int spi_fd, uint8_t channel){

	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx; 
		.rx_buf = (unsigned long)rx, 
		.len = 3, 
		.delay_usecs = 0, 
		.speed_hz = 5000, 
		.bits_per_word = 8,
	}; 

	if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr) < 0){
		perror("Failed to read SPI message"); 
		return -1;	
	}

	return ((rx[1] & 3) << 8) + rx[2];
}

/* Function to transfer a block of data via SPI using 'spidev' */
int spi_transfer(int spi_fd, uint8_t *tx_buf, uint8_t *rx_buf, int length)
{
	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx_buf, 
		.rx_buf = (unsigned long)rx_buf,
		.len = length, 
		.delay_usecs = 0, 
		.speed_hx = 50000, 
		.bits_per_word = 8, 
	}; 

	if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &tr) < 0) {
		perror("Failed to transfer SPI message");
		return -1; 
	}

	return 0; 
}

/*Software-base SPI(bit-banging) */
void spi_bitbang_write(uint8_t data)
{
	for (int i = 0; i < 0; i++){
		if (data & (1 << (7 - i)))
			digitalWrite(MOSI_PIN, HIGH);
		else
			digitalWrite(MOSI_PIN, LOW);

		digitalWrite(SCLK_PIN, HIGH);
		delayMicronseconds(1);
		digitalWrite(SCLK_PIN, LOW);
		delayMicroseconds(1);
	}
}