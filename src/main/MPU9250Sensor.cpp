#pragma once
#include "MPU9250Sensor.h"
#include <SPI.h>

/*//////////////////////////////////////////////////////
Create Register Read/Write Functions
//////////////////////////////////////////////////////*/

inline void MPU9250Sensor::writeRegister(uint8_t reg, uint8_t data) {
    SPI.beginTransaction(settings);
    digitalWrite(CS, LOW);
    SPI.transfer(reg & 0x7F);   // Ensure MSB is 0 for write
    SPI.transfer(data);         // Send data byte
    digitalWrite(CS, HIGH);
    SPI.endTransaction();
}

inline uint8_t MPU9250Sensor::readRegister(uint8_t reg) {
    SPI.beginTransaction(settings);
    digitalWrite(CS, LOW);
    SPI.transfer(reg | 0x80);               // Ensure MSB is 1 for read
    uint8_t data = SPI.transfer(0x00);      // Send dummy byte to receive data
    digitalWrite(CS, HIGH);
    SPI.endTransaction();
    return data;
}

/*//////////////////////////////////////////////////////
Write to AK8963 register with MPU9250's I2C Master interface
//////////////////////////////////////////////////////*/

bool MPU9250Sensor::AK8963Write(uint8_t reg, uint8_t data) {
    writeRegister(I2C_SLV4_ADDR, AK8963_I2C_ADDR);   // Write (bit7=0)
    writeRegister(I2C_SLV4_REG,  reg);
    writeRegister(I2C_SLV4_DO,   data);
    writeRegister(I2C_SLV4_CTRL, 0x80);              // Enable SLV4 transaction
    for (int i=0;i<50;i++) {
        uint8_t s = readReg(I2C_MST_STATUS);    // Wait for MPU9250 to complete I2C transaction with AK8963
        if (s & 0x40) return true;              // SLV4_DONE
        delayMicroseconds(200);
    }
    return false;
}

/*//////////////////////////////////////////////////////
Initialize MPU9250
//////////////////////////////////////////////////////*/

bool MPU9250Sensor::init() {
    pinMode(CS, OUTPUT);                                // Chip Select Pin
    digitalWrite(CS, HIGH);                             // Ensure device is deselected initially
    //Start SPI library
    SPI.begin();
    SPI.beginTransaction(settings);

    //MPU9250 to AK8963 to Magnetometer Initialization
    writeRegister(PWR_MGMT_1, 0x01);                                    // Wake up device
    delay(10);
    writeRegister(USER_CTRL,0x30);                                      // Enable I2C Master mode
    delay(10);
    writeRegister(I2C_MST_CTRL,0x0D);                                   // I2C Master clock at 400kHz
    delay(10);
    if (!ak8963Write(AK8963_CNTL1, AK8963_POWER_DOWN)) return false;    // Power down magnetometer
    delay(10);
    if (!ak8963Write(AK8963_CNTL1, AK8963_16BIT_CONT2)) return false;   // Set magnetometer to 16-bit resolution and continuous measurement mode 2 at 100Hz
    delay(10);

    writeRegister(I2C_SLV0_ADDR, 0x80 | AK8963_I2C_ADDR); // bit7=1 => read
    writeRegister(I2C_SLV0_REG,  AK8963_ST1);
    writeRegister(I2C_SLV0_CTRL, 0x88); // enable (bit7=1) + length=8

    SPI.endTransaction();
    return true;
}

/*//////////////////////////////////////////////////////
Read All Sensor Data from MPU9250
//////////////////////////////////////////////////////*/

bool MPU9250Sensor::readRawData(RawData& data) {
    if (!readAccelerometer(data.accelX, data.accelY, data.accelZ)) return false;
    if (!readGyroscope(data.gyroX, data.gyroY, data.gyroZ)) return false;
    if (!readMagnetometer(data.magX, data.magY, data.magZ)) return false;
    if (!readTemperature(data.temperature)) return false;
    return true;
}

bool MPU9250Sensor::readAccelerometer(std::int16_t& x, std::int16_t& y, std::int16_t& z) {
    // Read raw accelerometer data
    SPI.beginTransaction(settings);
    digitalWrite(CS,LOW);
    SPI.transfer(ACCEL_XOUT_H | 0x80);
    byte rawData[6];
    SPI.transferBytes(nullptr, rawData, 6);
    digitalWrite(CS,HIGH);
    SPI.endTransaction();
    // Store raw data
    x = (std::int16_t)(rawData[0] << 8 | rawData[1]);
    y = (std::int16_t)(rawData[2] << 8 | rawData[3]);
    z = (std::int16_t)(rawData[4] << 8 | rawData[5]);
    return true;
}

bool MPU9250Sensor::readGyroscope(std::int16_t& x, std::int16_t& y, std::int16_t& z) {
    // Read raw gyroscope data
    SPI.beginTransaction(settings);
    digitalWrite(CS,LOW);
    SPI.transfer(GYRO_XOUT_H | 0x80);
    byte rawData[6];
    SPI.transferBytes(nullptr, rawData, 6);
    digitalWrite(CS,HIGH);
    SPI.endTransaction();
    // Store raw data
    x = (std::int16_t)(rawData[0] << 8 | rawData[1]);
    y = (std::int16_t)(rawData[2] << 8 | rawData[3]);
    z = (std::int16_t)(rawData[4] << 8 | rawData[5]);
    return true;
}

bool MPU9250Sensor::readMagnetometer(std::int16_t& x, std::int16_t& y, std::int16_t& z) {
    // Read raw magnetometer data
    SPI.beginTransaction(settings);
    digitalWrite(CS,LOW);
    SPI.transfer(EXT_SENS_DATA_00 | 0x80); // Note: Magnetometer uses different register order from AK8963
    byte rawData[8];                       // Extra two bytes for status bytes
    SPI.transferBytes(nullptr, rawData, 6);
    digitalWrite(CS,HIGH);
    SPI.endTransaction();

    uint8_t status1 = rawData[0];
    if (!(status1 & 0x08)) return false;       // Check if data is ready

    uint8_t status2 = rawData[7];
    if (status2 & 0x08) return false;          // Check if overflow for data is invalid

    // Store raw data
    x = (std::int16_t)(rawData[2] << 8 | rawData[1]);
    y = (std::int16_t)(rawData[4] << 8 | rawData[3]);
    z = (std::int16_t)(rawData[6] << 8 | rawData[5]);
    return true;
}

bool MPU9250Sensor::readTemperature(std::int16_t& t) {
    // Read raw temperature data
    SPI.beginTransaction(settings);
    digitalWrite(CS,LOW);
    SPI.transfer(TEMP_OUT_H | 0x80);
    byte rawData[2];
    SPI.transferBytes(nullptr, rawData, 2);
    digitalWrite(CS,HIGH);
    SPI.endTransaction();
    // Store raw data
    t = (std::int16_t)(rawData[0] << 8 | rawData[1]);
    return true;
}