#pragma once

class DigitalMode {
    public:
    DigitalMode() = default;
    ~DigitalMode() = default;
    bool directionalTrigger();  //Detect directional gesture and return false 
                                //if direction is invert of current direction
};