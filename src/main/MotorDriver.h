#pragma once
#include <cstdint>

class Motor {
    public:
    Motor() = default;
    ~Motor() = default;
    void setSpeed();        //Set motor speed
    private:
    float getSpeed();       //Calculate motor speed with filters
    bool speedThreshold();  //Check minimum speed to set speed
};

class Steer {
    public:
    Steer() = default;
    ~Steer() = default;
    void setRotation();     //Set steering angle
    private:
    float getRotation();    //Calculate steering angle with filters
    bool angleThreshold();  //Check minimum angle to set steering
};

class VoltageMapper {
    public:
    VoltageMapper() = default;
    ~VoltageMapper() = default;
    float mapVoltage(float unit); //Map voltage from physical units to 0-3.3V range
    private:
    float minVoltage = 0.0f; //Minimum voltage for mapping
    float maxVoltage = 3.3f; //Maximum voltage for mapping
};