#pragma once
#include <cstdint>

struct RawData {
    /* Accelerometer Data */
    std::int16_t accelX, accelY, accelZ;
    /* Gyroscope Data */
    std::int16_t gyroX, gyroY, gyroZ;
    /* Magnetometer Data */
    std::int16_t magX, magY, magZ;
    /* Temperature Data */
    std::int16_t temperature;
};

class MPU9250Sensor {
   public:
    MPU9250Sensor() = default;
    ~MPU9250Sensor() = default;

    bool init();                          //Initialize communication interface
    bool readRawData(RawData& data);      //Read all sensor data into struct

   private:
    SPISettings settings(1000000, MSBFIRST, SPI_MODE0); //1MHz, MSB first, Mode 0

    bool readAccelerometer(std::int16_t& x, std::int16_t& y, std::int16_t& z);      //read raw accelerometer data
    bool readGyroscope(std::int16_t& x, std::int16_t& y, std::int16_t& z);          //read raw gyroscope data
    bool readMagnetometer(std::int16_t& x, std::int16_t& y, std::int16_t& z);       //read raw magnetometer data
    bool readTemperature(std::int16_t& t);                                          //read raw temperature data
    
    bool AK8963Write(uint8_t reg, uint8_t data);                                    //write to AK8963 register to get magnetometer data
    inline void writeRegister(uint8_t reg, uint8_t data);                           //write to MPU9250 register
    inline uint8_t readRegister(uint8_t reg);                                       //read from MPU9250 register
};