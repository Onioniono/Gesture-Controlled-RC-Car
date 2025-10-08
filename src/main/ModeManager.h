#pragma once

class Mode {
    public:
    Mode() = default;
    ~Mode() = default;
    void activeMode();  //Execute current control mode
    private:
    bool switchMode();  //Check if mode switch is changed
    int currentMode;    //Store current mode
};