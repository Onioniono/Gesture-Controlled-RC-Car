#pragma once
#include <cstdint>

class Motor {
    public:
    Motor() = default;
    ~Motor() = default;
    void setSpeed();        //Set motor speed
    private:
    float getSpeed();       //Calculate motor speed w/ filters
    bool speedThreshold();  //Check minimum speed to set speed
};

class Steer {
    public:
    Steer() = default;
    ~Steer() = default;
    void setRotation();     //Set steering angle
    private:
    float getRotation();    //Calculate steering angle
    bool angleThreshold();  //Check minimum angle to set steering
};