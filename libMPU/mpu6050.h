#ifndef __MPU6050_H__
#define __MPU6050_H__

#include "../ci2c/ci2c.h"

//----- Prototypes ------------------------------------------------------------//
void mpu_init(I2C_SLAVE * slave);
void mpu_send_data(I2C_SLAVE * slave, uint8_t Command);
void mpu_read_data(I2C_SLAVE * slave, int16_t *data);

//-----------------------------------------------------------------------------//

#endif