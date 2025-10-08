#pragma once
#include <cstdint>

class Motor {
    public:
    Motor() = default;
    ~Motor() = default;
    bool speedThreshold();  //Check minimum speed to set speed
    private:
    float getSpeed();       //Calculate motor speed
    void setSpeed();        //Set motor speed
};

class Steer {
    public:
    Steer() = default;
    ~Steer() = default;
    bool angleThreshold();  //Check minimum angle to set steering
    private:
    float getRotation();    //Calculate steering angle
    void setRotation();     //Set steering angle
};