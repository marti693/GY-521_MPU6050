# GY-521_MPU6050
A collection of libraries to interface with the GY-521 (MPU6050) using strictly C

To use these libraries, simply download them, and edit the compile_script.py to use your AVR library.

gyro.c is an example code, which will serve as an example on how to initialize and use the libraries.

cI2C by SMFSW is included in these libraries, with small changes to their code to make it compatible with mine.\n
Their work can be found at https://github.com/SMFSW/cI2C

Two videos were made demonstrating this code:
The first video cycles through each value obtainable by the mpu6050. It can be found at: https://drive.google.com/file/d/1OVv3Q9Qf7HbXkRrLTndzEeoWjj2XdFqf/view?usp=sharing
The second video only shows one value, for an easier to digest real-time display. It can be found at: https://drive.google.com/file/d/1OY4hzpASMWK80rkt_g8uldwfQkPocbo0/view?usp=sharing

# USAGE:

To use these libraries, simply include mpu6050.h in your c code, along with ci2c.h (and any other includes you might want)

First, a slave object must be made: ex - I2C_SLAVE [slave name];

Then, you have access to three methods specific to the MPU6050:

mpu_init(&[slave name])

this method only needs a pointer to your slave, and it will initialize the I2C protocol. (only works if the communication is to the MPU6050)

mpu_send_data(&[slave name], command)

this method will write data to the 0x6B register of the MPU6050. This is important, because to initialize the chip, a 0 must be written to that address.

mpu_read_data(&[slave name], data)

this method will read data from the MPU6050. the "data" variable here needs to be an array of uint16_t of length 7. After this is called, each address of the array will be written with a value from the MPU6050. 
***
The locations are as follows:
*data[0] - accelerometer_x
*data[1] - accelerometer_y
*data[2] - accelerometer_z
*data[3] - tempurature
*data[4] - gyro_x
*data[5] - gyro_y
*data[6] - gyro_z
