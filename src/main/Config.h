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
constexpr uint8_t ACCEL_XOUT_H = 0x3B;     // Accelerometer data start register
constexpr uint8_t GYRO_XOUT_H = 0x43;      // Gyroscope data start register
constexpr uint8_t TEMP_OUT_H = 0x41;       // Temperature data start register
constexpr uint8_t EXT_SENS_DATA_00 = 0x49; // Magnetometer data start register (External Sensor Data 00)

constexpr uint8_t PWR_MGMT_1 = 0x6B;        //Power Management (Sleep, Clock, Rest)
constexpr uint8_t USER_CTRL = 0x6A;         // Bit5: I2C_MST_EN Enable Internal I2C Master; Bit4: I2C_IF_DIS Disable I2C Slave
constexpr uint8_t I2C_MST_CTRL = 0x24;      // I2C Master Clock

constexpr uint8_t I2C_SLV0_ADDR = 0x25;     // I2C Slave 0 Address (AK8963 Read/Write)
constexpr uint8_t I2C_SLV0_REG = 0x26;      // I2C Slave 0 Register (AK8963 Register)
constexpr uint8_t I2C_SLV0_CTRL = 0x27;     // I2C Slave 0 Control (AK8963 Read Control)

constexpr uint8_t WHO_AM_I = 0x75;          // Expects 0x71

constexpr uint8_t I2C_SLV4_ADDR = 0x31;     // I2C Slave 4 Address
constexpr uint8_t I2C_SLV4_REG = 0x32;      // I2C Slave 4 Register
constexpr uint8_t I2C_SLV4_DO = 0x33;       // I2C Slave 4 Data Out
constexpr uint8_t I2C_SLV4_CTRL = 0x34;     // I2C Slave 4 Control to start read/write
constexpr uint8_t I2C_MST_STATUS = 0x36;    // I2C Master Status

/* AK8963 Register Addresses */
constexpr uint8_t AK8963_I2C_ADDR = 0x0C;       // I2C Address of Magnetometer
constexpr uint8_t AK8963_WIA = 0x00;            // who-am-i: Expects 0x48
constexpr uint8_t AK8963_ST1 = 0x02;            // Bit0: DRDY Data Ready 
constexpr uint8_t AK8963_HXL = 0x03;            // Magnometer 6 data bytes start here LSB-MSB
constexpr uint8_t AK8963_ST2 = 0x09;            // Bit3: HOFL Magnetic Sensor Overflow to release data
constexpr uint8_t AK8963_CNTL1 = 0x0A;          // Control 1 for Resolution and Mode
constexpr uint8_t AK8963_CNTL2 = 0x0B;          // Control 2 for Reset
constexpr uint8_t AK8963_POWER_DOWN = 0x00;     // Power Down
constexpr uint8_t AK8963_16BIT_CONT2 = 0x16;    // 16-bit, continuous measurement 2 (100 Hz)