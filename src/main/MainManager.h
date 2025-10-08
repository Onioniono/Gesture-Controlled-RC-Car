#pragma once

class MainManager {
    public:
    MainManager() = default;
    ~MainManager() = default;
    void activeMode();  //Execute current control mode
    private:
    bool switchMode();  //Check and switch between control modes
};