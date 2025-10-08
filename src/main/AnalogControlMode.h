#pragma once

class AnalogMode {
    public:
    AnalogMode() = default;
    ~AnalogMode() = default;
    float displacement();       //Calculate hand displacement relative to original position when switched to analog mode
};