// User data functions.  Modify these functions for your data items.
#include "UserTypes.h"
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU9250.h"
//------------------------------------------------------------------------------
MPU9250 mpu;

static uint32_t startMicros;
// Acquire a data record.
void acquireData(data_t* data) {
  data->time = micros();
  mpu.getMotion9(&data->ax, &data->ay, &data->az, 
                 &data->gx, &data->gy, &data->gz, 
                 &data->mx, &data->my, &data->mz);
}

// setup AVR I2C
void userSetup() {
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
  Wire.setClock(400000);
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif
  mpu.initialize();  
  
// Setup sensors.
//
  mpu.setFullScaleAccelRange(2); //set the accelerometer range to +/- 4g
  mpu.setFullScaleGyroRange(2); //set the gyrometer range to 1000

//  Serial.println(mpu.getFullScaleAccelRange());
//  Serial.println(mpu.getFullScaleGyroRange());
//  
    
//** full-scale accelerometer range. -32768 ~ 32767
// * 0 = +/- 2g
// * 1 = +/- 4g
// * 2 = +/- 8g
// * 3 = +/- 16g

//**full-scale Gyro range. -32768 ~ 32767
// * 0 = +/- 250 deg/s
// * 1 = +/- 500 deg/s
// * 2 = +/- 1000 deg/s
// * 3 = +/- 2000 deg/s

//------------------------------------------------------------------------------
  
}

// Print a data record.
void printData(Print* pr, data_t* data) {
  if (startMicros == 0) {
    startMicros = data->time;
  }
  pr->print(data->time- startMicros);
  pr->write(',');
  pr->print(data->ax);
  pr->write(',');
  pr->print(data->ay);
  pr->write(',');
  pr->print(data->az);
  pr->write(',');
  pr->print(data->gx);
  pr->write(',');
  pr->print(data->gy);
  pr->write(',');
  pr->print(data->gz);
  pr->write(',');
  pr->print(data->mx);
  pr->write(',');
  pr->print(data->my);
  pr->write(',');
  pr->println(data->mz);
}

// Print data header.
void printHeader(Print* pr) {
  startMicros = 0;
  pr->println(F("micros,ax,ay,az,gx,gy,gz,mx,my,mz"));
}
