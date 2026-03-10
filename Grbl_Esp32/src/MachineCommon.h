#pragma once

// Grbl setting that are common to all machines
// It should not be necessary to change anything herein

#ifndef GRBL_SPI_FREQ
// You can override these by defining them in a board file.
// To override, you must set all of them
//-1 means use the default board pin
#    ifdef ESP32_C3
        // ESP32-C3 的默认 SPI 引脚
#        define GRBL_SPI_SS     GPIO_NUM_10
#        define GRBL_SPI_MOSI   GPIO_NUM_7
#        define GRBL_SPI_MISO   GPIO_NUM_2
#        define GRBL_SPI_SCK    GPIO_NUM_6
#    else
#        define GRBL_SPI_SS     GPIO_NUM_5
#        define GRBL_SPI_MOSI   GPIO_NUM_23
#        define GRBL_SPI_MISO   GPIO_NUM_19
#        define GRBL_SPI_SCK    GPIO_NUM_18
#    endif
#    define GRBL_SPI_FREQ 4000000
#endif

// ESP32 CPU Settings
const uint32_t fTimers = 80000000;  // a reference to the speed of ESP32 timers

// =============== Don't change or comment these out ======================
// They are for legacy purposes and will not affect your I/O

const int STEP_MASK = B111111;

const int PROBE_MASK = 1;
