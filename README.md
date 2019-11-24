# LowLatencyLoggerMPU9250
MPU9250 version of LowLatencyLogger_MPU6050, originally belongs to Bill Greiman's SDFAT Arduino library.
also includes codes from Jeff Rowberg's I2C-MPU library 

It logs MPU9250's Accelerometer, Gyroscope and Magnetometer raw data to SD card (my case, Pin 4)

I wanted to run the code without serial communications, therefore I modded the code slightly and serial commands are replaced with digital pin inputs. you might easyily rollback.

As my understanding, MPU9250 reads Magnetometer from independently attached distinct sensor unlike Acc./Gyroscope. therefore it requires waking the magnetometer up before each reading, which requires inevitable delay. This means you never be able to sample 9doF data above ~40Hz (it's a pain in my ass. somebody help me)

My conclusion after finishing building my standalone lowlatencyloggermpu9250 device was.... just buy Arduino 33 BLE, and go serial comm via bluetooth for MPU data internalized in latest arduino nanos. That will be efficient and both in device space and data collectings.

