cmake_minimum_required(VERSION 4.0)
project(SmartSleep)

set(CMAKE_CXX_STANDARD 17)
set(RENESAS_CORE "$ENV{HOME}/Library/Arduino15/packages/arduino/hardware/renesas_uno/1.5.3")
set(ARDUINO_LIBS "$ENV{HOME}/Documents/Arduino/libraries")

include_directories(main)
include_directories(main/include
        ${RENESAS_CORE}/libraries/Arduino_LED_Matrix/src
        ${RENESAS_CORE}/cores/arduino
        ${ARDUINO_LIBS}/ArduinoGraphics/src
)

add_executable(SmartSleep
        main/include/IButtonManager.h
        main/include/IDisplayManager.h
        main/include/IDisplayManagerTypes.h
        main/LEDMatrixDisplayManager.cpp
        main/LEDMatrixDisplayManager.h
        main/main.ino
)
