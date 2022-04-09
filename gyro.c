#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include "libLCD/hd44780.h"
#include "libLCD/IO_Macros.h"
#include "ci2c/ci2c.h"
#include "libMPU/mpu6050.h"

//Copyright Nathan Martin
//Some code borrowed from Peter Jamieson

/* PROTOTPYES */
void my_delay_ms(unsigned int delay);



int main(void)
{

	//Setup
	LCD_Setup();
	
	//Print a line to check that LCD is working
	LCD_GotoXY(0, 0);
	LCD_PrintString("LCD is Working");
	
	/* delay before protocol*/
	
	I2C_SLAVE MPU; //create slave struct (necessary for I2C function calls
	//mpu_init(&MPU); //initialize I2C protocol (mpu_init initializes to the MPU6050)
	I2C_init(I2C_STD);		// init with Fast Mode (400KHz)
	I2C_slave_init(&MPU, 0x68, I2C_8B_REG);
	
	
	int16_t data[7];
	//Data array to contain data read from chip
	//data[0] - accelerometer_x
	//data[1] - accelerometer_y
	//data[2] - accelerometer_z
	//data[3] - tempurature
	//data[4] - gyro_x
	//data[5] - gyro_y
	//data[6] - gyro_z
	
	mpu_send_data(&MPU, 0x00);
	
	
	/* commence communication */
	while(1) {
		
		mpu_read_data(&MPU, data); //read the data
		
		//Once data is read, all you need to do is access it with data[x] where x is the value you would like to read
		
		//The following cycles through each value, and prints it out
		LCD_Clear();
		LCD_GotoXY(0,0);
		LCD_PrintString("acc_x");
		LCD_GotoXY(0,1);
		LCD_PrintInteger(data[0]);
		my_delay_ms(500);
		
		
		LCD_Clear();
		LCD_GotoXY(0,0);
		LCD_PrintString("acc_y");
		LCD_GotoXY(0,1);
		LCD_PrintInteger(data[1]);
		my_delay_ms(500);
		
		LCD_Clear();
		LCD_GotoXY(0,0);
		LCD_PrintString("acc_z");
		LCD_GotoXY(0,1);
		LCD_PrintInteger(data[2]);
		my_delay_ms(500);
		
		LCD_Clear();
		LCD_GotoXY(0,0);
		LCD_PrintString("temp");
		LCD_GotoXY(0,1);
		LCD_PrintInteger(data[3]);
		my_delay_ms(500);
		
		LCD_Clear();
		LCD_GotoXY(0,0);
		LCD_PrintString("gyro_x");
		LCD_GotoXY(0,1);
		LCD_PrintInteger(data[4]);
		my_delay_ms(500);
		
		LCD_Clear();
		LCD_GotoXY(0,0);
		LCD_PrintString("gyro_y");
		LCD_GotoXY(0,1);
		LCD_PrintInteger(data[5]);
		my_delay_ms(500);
		
		LCD_Clear();
		LCD_GotoXY(0,0);
		LCD_PrintString("gyro_z");
		LCD_GotoXY(0,1);
		LCD_PrintInteger(data[6]);
		my_delay_ms(500);
		
	}
	
	return 0;
}
