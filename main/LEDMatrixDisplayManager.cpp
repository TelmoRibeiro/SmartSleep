#include "LEDMatrixDisplayManager.h"

LEDMatrixDisplayManager::LEDMatrixDisplayManager(void) : context({}) {
}

LEDMatrixDisplayManager::~LEDMatrixDisplayManager(void) {
}

const Font& LEDMatrixDisplayManager::toArduinoFont(TextFontSize fontSize) const {
    switch (fontSize) {
        case TextFontSize::Font5x7: return Font_5x7;
        default:                    return Font_4x6;
    }
}

LEDMatrixDisplayManager* LEDMatrixDisplayManager::getInstance(void) {
    static LEDMatrixDisplayManager instance;
    return &instance;
}

bool LEDMatrixDisplayManager::isInitialised(void) const {
    return this->context.isInitialised == true;
}

void LEDMatrixDisplayManager::initialise(void) {
    if (this->isInitialised() == true) {
        return;
    }
    this->start();
    this->context.isInitialised = true;
}

void LEDMatrixDisplayManager::start(void) {
    if (this->isInitialised() == true) {
        return;
    }
    this->context.LEDMatrix.begin();
}

void LEDMatrixDisplayManager::clear(void) {
    if (this->isInitialised() == false) {
        return;
    }
    this->context.LEDMatrix.clear();
}

void LEDMatrixDisplayManager::play(bool shouldLoop) {
    if (this->isInitialised() == false) {
        return;
    }
    this->context.shouldLoop = shouldLoop;
    context.LEDMatrix.beginDraw();
    context.LEDMatrix.stroke(this->context.text.colour);
    context.LEDMatrix.textScrollSpeed(this->context.text.scrollSpeedMS);
    context.LEDMatrix.textFont(toArduinoFont(this->context.text.fontSize));
    context.LEDMatrix.beginText(this->context.text.x, this->context.text.y, this->context.text.colour);
    context.LEDMatrix.endText(static_cast<int32_t>(this->context.text.scrollDirection));
    context.LEDMatrix.endDraw();
    this->context.LEDMatrix.println(this->context.text.content.c_str());
}

void LEDMatrixDisplayManager::update(void) {
    if (this->isInitialised() == false) {
        return;
    }
    if (this->isDone() == true && this->context.shouldLoop == true) {
        this->play(this->context.shouldLoop);
    }
}

void LEDMatrixDisplayManager::showStaticText(const std::string& text, int32_t x, int32_t y) {
    if (this->isInitialised() == false) {
        return;
    }
    this->context.text.content = text;
    this->context.text.x = x;
    this->context.text.y = y;
    this->context.text.scrollDirection = ScrollDirection::Static;
}

void LEDMatrixDisplayManager::showScrollableText(const std::string& text, ScrollDirection scrollDirection, int32_t x, int32_t y) {
    if (this->isInitialised() == false) {
        return;
    }
    this->context.text.content = text;
    this->context.text.x = x;
    this->context.text.y = y;
    this->context.text.scrollDirection = scrollDirection;
}

bool LEDMatrixDisplayManager::isDone(void) const {
    if (this->isInitialised() == false) {
        return true;
    }
    return this->context.LEDMatrix.sequenceDone() == true;
}

void LEDMatrixDisplayManager::setTextFontSize(TextFontSize textFontSize) {
    if (this->isInitialised() == false) {
        return;
    }
    this->context.text.fontSize = textFontSize;
}

TextFontSize LEDMatrixDisplayManager::getTextFontSize(void) const {
    if (this->isInitialised() == false) {
        return TextFontSize::Font4x6;
    }
    return this->context.text.fontSize;
}

void LEDMatrixDisplayManager::setTextColour(uint32_t textColour) {
    if (this->isInitialised() == false) {
        return;
    }
    this->context.text.colour = textColour;
}

uint32_t LEDMatrixDisplayManager::getTextColour(void) const {
    if (this->isInitialised() == false) {
        return RED_HEX_COLOUR;
    }
    return this->context.text.colour;
}

void LEDMatrixDisplayManager::setScrollSpeedMS(uint32_t scrollSpeedMS) {
    if (this->isInitialised() == false) {
        return;
    }
    this->context.text.scrollSpeedMS = scrollSpeedMS;
}

uint32_t LEDMatrixDisplayManager::getScrollSpeedMS(void) const {
    if (this->isInitialised() == false) {
        return 100U;
    }
    return this->context.text.scrollSpeedMS;
}