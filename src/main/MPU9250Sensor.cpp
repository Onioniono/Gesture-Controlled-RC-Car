#pragma once
#include "MPU9250Sensor.h"
#include <SPI.h>

bool MPU9250Sensor::init() {
    pinMode(CS, OUTPUT);     //Chip Select Pin
    digitalWrite(CS, HIGH);  // Ensure device is deselected initially
    //Start SPI library
    SPI.begin();
    SPISettings settings(1000000, MSBFIRST, SPI_MODE0); //1MHz, MSB first, Mode 0
    SPI.beginTransaction(settings);
    SPI.endTransaction();
    return true;
}

//Read Raw Data from all sensors
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
    SPI.transferBytes(NULL, rawData, 6);
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
    SPI.transferBytes(NULL, rawData, 6);
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

    // Store raw data
    x = (std::int16_t)(rawData[0] << 8 | rawData[1]);
    y = (std::int16_t)(rawData[2] << 8 | rawData[3]);
    z = (std::int16_t)(rawData[4] << 8 | rawData[5]);
    return true;
}

bool MPU9250Sensor::readTemperature(std::int16_t& t) {
    // Read raw temperature data
    SPI.beginTransaction(settings);
    digitalWrite(CS,LOW);
    SPI.transfer(TEMP_OUT_H | 0x80);
    byte rawData[2];
    SPI.transferBytes(NULL, rawData, 2);
    digitalWrite(CS,HIGH);
    SPI.endTransaction();
    // Store raw data
    t = (std::int16_t)(rawData[0] << 8 | rawData[1]);
    return true;
}