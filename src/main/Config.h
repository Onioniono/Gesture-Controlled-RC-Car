#pragma once
#include <cstdint>
/* MPU9250 PCB Constraints for SPI Communication */
constexpr int SCK = 2;  // SPI Serial Clock (connects to SCL on breakout)
constexpr int MISO = 6; // SPI Master In Slave Out (connects to AD0 on breakout)
constexpr int MOSI = 3; // SPI Master Out Slave In (connects to SDA on breakout)
constexpr int CS = 8;   // SPI Chip Select (connects to NCS on breakout)

/* ESP32 Constraints for SPI Communication */
constexpr int ESP_SCK = 11;         // SPI Serial Clock (connects to SCL on breakout)
constexpr int ESP_MOSI_PIN = 10 ;   // SPI Master Out Slave In (connects to SDA on breakout)
constexpr int ESP_MISO_PIN = 9;     // SPI Master In Slave Out (connects to AD0 on breakout)
constexpr int ESP_CS_PIN = 8 ;      // SPI Chip Select (connects to NCS on breakout)

/* ESP32 Outputs */
constexpr int ESP_MOTOR_PIN = 6;        //Motor Output
constexpr int ESP_STEERING_PIN = 7;     //Steering Output

/* MPU9250 Register Addresses */
constexpr uint8_t ACCEL_XOUT_H = 0x3B;
constexpr uint8_t GYRO_XOUT_H = 0x43;
constexpr uint8_t TEMP_OUT_H = 0x41;