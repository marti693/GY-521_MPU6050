#include "../ci2c/ci2c.h"
#include "mpu6050.h"

//Initialize everything (master and slave)
void mpu_init(I2C_SLAVE * slave){
	I2C_init(I2C_STD); // standard mode (100kHz)
	I2C_slave_init(slave, 0x68, I2C_8B_REG); // init slave (address set to MPU6050)
	mpu_send_data(slave, 0x00);
}

void mpu_send_data(I2C_SLAVE * slave, uint8_t msg){
	I2C_write(slave, 0x6B, &msg, 1);
}

void mpu_read_data(I2C_SLAVE * slave, int16_t *data){
	uint16_t size = 1;
	int8_t output1[7];
	int8_t output2[7];
	I2C_read(slave, 0x3B, &output1[0], size);
	//I2C_read(slave, 0x3C, &output2[0], size);
	I2C_read(slave, 0x3D, &output1[1], size);
	//I2C_read(slave, 0x3E, &output2[1], size);
	I2C_read(slave, 0x3F, &output1[2], size);
	//I2C_read(slave, 0x40, &output2[2], size);
	I2C_read(slave, 0x41, &output1[3], size);
	//I2C_read(slave, 0x42, &output2[3], size);
	I2C_read(slave, 0x43, &output1[4], size);
	//I2C_read(slave, 0x44, &output2[4], size);
	I2C_read(slave, 0x45, &output1[5], size);
	//I2C_read(slave, 0x46, &output2[5], size);
	I2C_read(slave, 0x47, &output1[6], size);
	//I2C_read(slave, 0x48, &output2[6], size);
	int i;
	for (i = 0; i < 8; i++) {
		data[i] = (output1[i] << 8) | output2[i];
	}
}

