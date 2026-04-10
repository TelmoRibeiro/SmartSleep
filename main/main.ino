#include "LEDMatrixDisplayManager.h"

void setup() {
    LEDMatrixDisplayManager* displayManager = LEDMatrixDisplayManager::getInstance();
    displayManager->initialise();
    displayManager->showScrollableText("Hello World", ScrollDirection::Leftward);
    displayManager->play(true);
}

void loop() {
    LEDMatrixDisplayManager::getInstance()->update();
}