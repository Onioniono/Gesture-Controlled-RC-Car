#pragma once
#include <cstdint>
class Motor {
    public:
    Motor() = default;
    ~Motor() = default;
    float getSpeed() const;
};

class Wheel {
    public:
    Wheel() = default;
    ~Wheel() = default;
    float getRotation() const;
};