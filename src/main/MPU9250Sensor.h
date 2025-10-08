#pragma once
#include <cstdint>
struct SensorData {
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

    bool init();
    bool readSensorData(SensorData& data);

   private:
    bool readAccelerometer(std::int16_t& x, std::int16_t& y, std::int16_t& z);
    bool readGyroscope(std::int16_t& x, std::int16_t& y, std::int16_t& z);
    bool readMagnetometer(std::int16_t& x, std::int16_t& y, std::int16_t& z);
    bool readTemperature(std::int16_t& temperature);
};