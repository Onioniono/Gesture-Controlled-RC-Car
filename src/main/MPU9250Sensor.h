#pragma once
#include <cstdint>
struct sensorData {
    /* Accelerometer Data */
    std::int16_t accelX;
    std::int16_t accelY;
    std::int16_t accelZ;
    /* Gyroscope Data */
    std::int16_t gyroX;
    std::int16_t gyroY;
    std::int16_t gyroZ;
    /* Magnetometer Data */
    std::int16_t magX;
    std::int16_t magY;
    std::int16_t magZ;
    /* Temperature Data */
    std::int16_t temp;
};