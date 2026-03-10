#pragma once
// clang-format off

/*
    3axis_v4.h
    Part of Grbl_ESP32

    Pin assignments for the ESP32 Development Controller, v4.1 and later.
    https://github.com/bdring/Grbl_ESP32_Development_Controller
    https://www.tindie.com/products/33366583/grbl_esp32-cnc-development-board-v35/

    2018    - Bart Dring
    2020    - Mitch Bradley

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME            "ESP32_WRITE_V0.1"
#define X_STEP_PIN              GPIO_NUM_27
#define X_DIRECTION_PIN         GPIO_NUM_26

#define Y_STEP_PIN              GPIO_NUM_33
#define Y_DIRECTION_PIN         GPIO_NUM_32

// #define Z_STEP_PIN              GPIO_NUM_15
// #define Z_DIRECTION_PIN         GPIO_NUM_12
#define Z_SERVO_PIN             GPIO_NUM_15

// OK to comment out to use pin for other features
#define STEPPERS_DISABLE_PIN    GPIO_NUM_25

#define X_LIMIT_PIN             GPIO_NUM_34
#define Y_LIMIT_PIN             GPIO_NUM_35
// #define Z_LIMIT_PIN             GPIO_NUM_15

#define SPINDLE_TYPE            SpindleType::NONE
#define SERVO_TIMER_INTERVAL    75
// #define SPINDLE_OUTPUT_PIN      GPIO_NUM_22   // labeled SpinPWM
// #define SPINDLE_ENABLE_PIN      GPIO_NUM_39  // labeled SpinEnbl






#define DEFAULT_HOMING_DIR_MASK     (bit(X_AXIS) | bit(Y_AXIS) | bit (Z_AXIS)) // these home negative


#define DEFAULT_X_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Y_MAX_RATE 5000.0 // mm/min
#define DEFAULT_Z_MAX_RATE 5000.0 // mm/min

#define DEFAULT_X_ACCELERATION 200.0 // mm/sec^2. 200 mm/sec^2 = 720000 mm/min^2
#define DEFAULT_Y_ACCELERATION 200.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 200.0 // mm/sec^2


#define DEFAULT_X_STEPS_PER_MM 26.67
#define DEFAULT_Y_STEPS_PER_MM 26.67
#define DEFAULT_Z_STEPS_PER_MM 100.0 // This is percent in servo mode



#define DEFAULT_X_MAX_TRAVEL 60.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Y_MAX_TRAVEL 60.0 // mm NOTE: Must be a positive value.
#define DEFAULT_Z_MAX_TRAVEL 8.0 // This is percent in servo mode SG90最大行程
#define SERVO_ONE_WAY_INTERVAL 5  // SG90单向行程

// OLED屏幕配置
#define DISPLAY_CODE_FILENAME "Custom/oled_basic.cpp"
#    define OLED_SDA GPIO_NUM_14
#    define OLED_SCL GPIO_NUM_13