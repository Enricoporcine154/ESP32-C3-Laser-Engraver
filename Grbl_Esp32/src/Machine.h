#pragma once

// This file is where you choose the machine type, by including
// one or more machine definition files as described below.

#ifndef MACHINE_FILENAME

// !!! For initial testing, start with test_drive.h which disables
// all I/O pins

// 根据芯片类型选择配置文件
#if defined(ESP32C3) || defined(ARDUINO_ESP32C3_DEV)
    // ESP32-C3 激光雕刻机配置
    #include "Machines/esp32_c3_write.h"
#else
    // ESP32 写字机配置
    #include "Machines/esp32_write_V0.1.h"
#endif
// #    include "Machines/test_drive.h"

// !!! For actual use, change the line above to select a board
// from Machines/, for example:
// #include "Machines/3axis_v4.h"

// === OEM Single File Configuration Option
// OEMs that wish to publish source code that is configured for a
// specific machine may put all of their configuration definitions
// directly in this file, without including any other file above.

#else

// By using the external environment to define MACHINE_FILENAME,
// a configuration can be chosen without editing this file.
// That is useful for automated testing scripts.
//
// For example, when using the platformio compilation environment
// under Linux, you could issue the following command line:
//   PLATFORMIO_BUILD_FLAGS=-DMACHINE_FILENAME=3axis_v4.h platformio run
//
// Under Windows, using PowerShell, the command would be:
//   $env:PLATFORMIO_BUILD_FLAGS='-DMACHINE_FILENAME=3axis_v4.h'; platformio run
//
// When using the Arduino IDE, there is no easy way to pass variables
// to the compiler, so this feature is not useful for Arduino.
//
// MACHINE_FILENAME must not include the Machines/ path prefix; it is
// supplied automatically.

// MACHINE_PATHNAME_QUOTED constructs a path that is suitable for #include
#    define MACHINE_PATHNAME_QUOTED(name) <src/Machines/name>

#    include MACHINE_PATHNAME_QUOTED(MACHINE_FILENAME)

#endif  // MACHINE_FILENAME
