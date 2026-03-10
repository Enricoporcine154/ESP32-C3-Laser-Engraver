#pragma once

// this is the pulse range of a the servo. Typical servos are 0.001 to 0.002 seconds
// some servos have a wider range. You can adjust this here or in the calibration feature
// SG90 PWM脉冲周期为20ms左右
// ______
// |    |___________________________________________| PWM波形示意图
// 高电平为0.5ms-2.5ms
// 高电平0.5ms和2.5ms分别对应舵机的0°和满行程度数
// 下面是180°舵机的高电平时间与电机角度的对应关系
// 0.5ms       0°
// 1.0ms       45°
// 1.5ms       90°
// 2.0ms       135°
// 2.5ms       180°
// 设置舵机角度范围为45°~90°
const double SERVO_MIN_PULSE_SEC = 0.001;  // min pulse in seconds
const double SERVO_MAX_PULSE_SEC = 0.0015;  // max pulse in seconds

const double SERVO_POSITION_MIN_DEFAULT = 0.0;   // mm
const double SERVO_POSITION_MAX_DEFAULT = 20.0;  // mm

const int SERVO_PULSE_FREQ = 50;  // 50Hz ...This is a standard analog servo value. Digital ones can repeat faster

const int SERVO_PULSE_RES_BITS  = 16;     // bits of resolution of PWM (16 is max)
const int SERVO_PULSE_RES_COUNT = 65535;  // see above  TODO...do the math here 2^SERVO_PULSE_RES_BITS

const double SERVO_TIME_PER_BIT = ((1.0 / (double)SERVO_PULSE_FREQ) / ((double)SERVO_PULSE_RES_COUNT));  // seconds

const uint16_t SERVO_MIN_PULSE = (uint16_t)(SERVO_MIN_PULSE_SEC / SERVO_TIME_PER_BIT);  // in timer counts
const uint16_t SERVO_MAX_PULSE = (uint16_t)(SERVO_MAX_PULSE_SEC / SERVO_TIME_PER_BIT);  // in timer counts

const uint16_t SERVO_PULSE_RANGE = (SERVO_MAX_PULSE - SERVO_MIN_PULSE);

const double SERVO_TIMER_INT_FREQ = 50.0;  // Hz This is the task frequency

const int SERVO_FULL_MOVE_TIME = 750;  // rtos ticks
