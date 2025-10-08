#pragma once
/* MPU9250 PCB Constraints */
constexpr int MPU_SCL_PIN = 2;   // Serial Clock
constexpr int MPU_SDA_PIN = 3;   // Serial Data
constexpr int MPU_ECL_PIN = 5;   // External Clock
constexpr int MPU_NCS_PIN = 8;   // Chip Select
constexpr int MPU_ADO_PIN = 6;   // Address Select to gnd
/* ESP32 Constraints */
//Inputs
constexpr int ESP_SCL_PIN = 11;  // Serial Clock
constexpr int ESP_SDA_PIN = 10 ; // Serial Data
constexpr int ESP_ECL_PIN = 9;   // External Clock
constexpr int ESP_NCS_PIN = 8 ;  // Chip Select
//Outputs
constexpr int ESP_M_PIN = 6;     //Motor Output
constexpr int ESP_S_PIN = 7;     //Steering Output