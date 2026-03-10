#pragma once
// clang-format off

// ⚠️ 如需重置设置，取消下行注释后上传一次
// #define FORCE_SETTINGS_RESET

/*
    esp32_c3_write.h
    ESP32-C3 激光雕刻机 配置文件 - 基础版本
    
    开发板型号: ESP32-C3FH4 (内置Flash版本)
    Part of Grbl_ESP32
*/

#define MACHINE_NAME            "ESP32_C3_LASER"

// ============ ESP32-C3 兼容性配置 ============
#ifdef USE_RMT_STEPS
    #undef USE_RMT_STEPS
#endif

#ifdef USE_I2S_STEPS
    #undef USE_I2S_STEPS
#endif

// ============ 2轴配置 ============
#define N_AXIS 2

#define SERVO_ONE_WAY_INTERVAL 5

// ============ X轴配置 ============
#define X_STEP_PIN              GPIO_NUM_0
#define X_DIRECTION_PIN         GPIO_NUM_4

// ============ Y轴配置 ============
#define Y_STEP_PIN              GPIO_NUM_1
#define Y_DIRECTION_PIN         GPIO_NUM_5

// ============ 方向反转 ============
// bit1=Y轴反转
#define DEFAULT_DIRECTION_INVERT_MASK   2 //0b10 X 不反，Y 反 

// ============ 电机使能 ============
#define STEPPERS_DISABLE_PIN    GPIO_NUM_10

// ============ 激光配置 ============
#define SPINDLE_TYPE            SpindleType::LASER
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_3
#define LASER_OUTPUT_PIN        GPIO_NUM_3

#define DEFAULT_LASER_MODE      0//默认激光关闭 对应grbl $32
#define DEFAULT_SPINDLE_RPM_MAX 1000
#define DEFAULT_SPINDLE_RPM_MIN 0

// ============ 禁用所有限位和归零功能 ============
// 不定义限位引脚，完全禁用限位功能
// #define X_LIMIT_PIN          GPIO_NUM_7
// #define Y_LIMIT_PIN          GPIO_NUM_6

#define DEFAULT_HOMING_ENABLE   0
#define DEFAULT_HARD_LIMIT_ENABLE 0
#define DEFAULT_SOFT_LIMIT_ENABLE 0

// ============ 运动参数 ============
#define DEFAULT_X_MAX_RATE 3000.0 //mm/min
#define DEFAULT_Y_MAX_RATE 3000.0 //mm/min

#define DEFAULT_X_ACCELERATION 100.0 //mm/s^2
#define DEFAULT_Y_ACCELERATION 100.0 //mm/s^2

// PL15S-020 电机: 18度步进角, 20步/圈, 导程3mm
// A4988 驱动板 16细分: 20 × 16 = 320 微步/圈
// steps/mm = 320 / 3 = 106.67
#define DEFAULT_X_STEPS_PER_MM 106.67
#define DEFAULT_Y_STEPS_PER_MM 106.67

#define DEFAULT_X_MAX_TRAVEL 42.0
#define DEFAULT_Y_MAX_TRAVEL 42.0

// ============ 电机使能设置 ============
#define DEFAULT_INVERT_ST_ENABLE 0

// ============ 电机空闲时间 ============
// 255 = 永不断电
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 255

// ============ 禁用安全门 ============
#ifdef CONTROL_SAFETY_DOOR_PIN
    #undef CONTROL_SAFETY_DOOR_PIN
#endif
#ifdef ENABLE_SAFETY_DOOR_INPUT_PIN
    #undef ENABLE_SAFETY_DOOR_INPUT_PIN
#endif
