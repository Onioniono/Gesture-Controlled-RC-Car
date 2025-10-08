#pragma once
#include "MotorDriver.h"
#include "MPU9250Sensor.h"
#include <cmath>

float VoltageMapper::mapVoltage(float unit) {
    // Map the input voltage to a usable range [0.0, 3.3]
    float voltage = 0; // Placeholder for actual mapping caluclations
    return voltage;
}

void Motor::setSpeed() {
    // Set motor speed based on calculated speed
    float speed = getSpeed();
    if (speedThreshold()) {
        // Code to set motor speed
    }
}

float Motor::getSpeed() {
    // Calculate motor speed with filters
    float speed = 0; // Placeholder for actual speed calculation
    return speed;
}

bool Motor::speedThreshold() {
    // Check if the speed is above a certain threshold
    float speed = getSpeed();
    return speed > 0.1f; // Example threshold
}

void Steer::setRotation() {
    // Set steering angle based on calculated rotation
    float rotation = getRotation();
    if (angleThreshold()) {
        // Code to set steering angle
    }
}

float Steer::getRotation() {
    // Calculate steering angle with filters
    float rotation = 0; // Placeholder for actual rotation calculation
    return rotation;
}

bool Steer::angleThreshold() {
    // Check if the angle is above a certain threshold
    float rotation = getRotation();
    return std::abs(rotation) > 5.0f; // Example threshold in degrees
}