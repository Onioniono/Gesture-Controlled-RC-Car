#include "ModeManager.h"

bool Mode::switchMode() {
    //If switch pin != currentMode, return true
    return false;
}

void Mode::activeMode() {
    if (switchMode()) {
        currentMode = (currentMode + 1) % 2; //Assuming 2 modes: 0 and 1
    }
    //Execute actions based on currentMode
}