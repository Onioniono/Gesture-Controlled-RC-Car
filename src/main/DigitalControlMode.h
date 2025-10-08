#pragma once

class DigitalMode {
    public:
    DigitalMode() = default;
    ~DigitalMode() = default;
    bool cooldown();        //Cooldown period between gesture detections
    private:
    void filterData();        //Filter raw sensor data for stability
};