#pragma once
/* MPU9250 PCB Constraints */
#define MPU_SCL_PIN 2   // Serial Clock
#define MPU_SDA_PIN 3   // Serial Data
#define MPU_ECL_PIN 5   // External Clock
#define MPU_NCS_PIN 8   // Chip Select
#define MPU_ADO_PIN 6   // Address Select to gnd
/* ESP32 Constraints */
//Inputs
#define ESP_SCL_PIN 11  // Serial Clock
#define ESP_SDA_PIN 10  // Serial Data
#define ESP_ECL_PIN 9   // External Clock
#define ESP_NCS_PIN 8   // Chip Select
//Outputs
#define ESP_D_PIN 6     //Digital Output
#define ESP_A_PIN 7     //Analog Output