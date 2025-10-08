#pragma once

class AnalogMode {
    public:
    AnalogMode() = default;
    ~AnalogMode() = default;
    bool accelTrigger(); //Detect acceleration threshold
};