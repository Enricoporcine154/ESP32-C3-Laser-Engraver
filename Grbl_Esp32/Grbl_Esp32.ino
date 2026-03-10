/*
  Grbl_ESP32.ino - Header for system level commands and real-time processes
  Part of Grbl
  Copyright (c) 2014-2016 Sungeun K. Jeon for Gnea Research LLC

	2018 -	Bart Dring This file was modified for use on the ESP32
					CPU. Do not use this with Grbl for atMega328P

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "src/Grbl.h"

// ============ 自动测试模式 ============
// 设为 true 启用自动测试，烧录后上电会自动测试电机
// 测试完成后改回 false 并重新烧录
#define AUTO_TEST_MODE false

#if AUTO_TEST_MODE

// 引脚定义（与 esp32_c3_write.h 一致）
#define TEST_X_STEP     0
#define TEST_X_DIR      4
#define TEST_Y_STEP     1
#define TEST_Y_DIR      5
#define TEST_EN         10
#define TEST_LASER      3

void autoTestMotors() {
    // 初始化引脚
    pinMode(TEST_X_STEP, OUTPUT);
    pinMode(TEST_X_DIR, OUTPUT);
    pinMode(TEST_Y_STEP, OUTPUT);
    pinMode(TEST_Y_DIR, OUTPUT);
    pinMode(TEST_EN, OUTPUT);
    pinMode(TEST_LASER, OUTPUT);
    
    // 使能电机（低电平使能）
    digitalWrite(TEST_EN, LOW);
    
    // 等待3秒让用户准备观察
    delay(3000);
    
    // ========== 新测试：GPIO0 慢速闪烁测试 ==========
    // 用万用表测 GPIO0，应该看到电压在0V和3.3V之间变化
    for (int i = 0; i < 10; i++) {
        digitalWrite(TEST_X_STEP, HIGH);
        delay(500);  // 0.5秒高电平
        digitalWrite(TEST_X_STEP, LOW);
        delay(500);  // 0.5秒低电平
    }
    
    delay(1000);
    
    // ========== 测试1: X轴正向（更慢速度） ==========
    digitalWrite(TEST_X_DIR, HIGH);  // 设置方向
    for (int i = 0; i < 100; i++) {  // 发送100个脉冲
        digitalWrite(TEST_X_STEP, HIGH);
        delayMicroseconds(5000);  // 5ms = 200Hz，非常慢
        digitalWrite(TEST_X_STEP, LOW);
        delayMicroseconds(5000);
    }
    
    delay(1000);
    
    // ========== 测试2: X轴反向 ==========
    digitalWrite(TEST_X_DIR, LOW);  // 反方向
    for (int i = 0; i < 100; i++) {
        digitalWrite(TEST_X_STEP, HIGH);
        delayMicroseconds(5000);
        digitalWrite(TEST_X_STEP, LOW);
        delayMicroseconds(5000);
    }
    
    delay(1000);
    
    // ========== 测试3: Y轴正向 ==========
    digitalWrite(TEST_Y_DIR, HIGH);
    for (int i = 0; i < 100; i++) {
        digitalWrite(TEST_Y_STEP, HIGH);
        delayMicroseconds(5000);
        digitalWrite(TEST_Y_STEP, LOW);
        delayMicroseconds(5000);
    }
    
    delay(1000);
    
    // ========== 测试4: Y轴反向 ==========
    digitalWrite(TEST_Y_DIR, LOW);
    for (int i = 0; i < 100; i++) {
        digitalWrite(TEST_Y_STEP, HIGH);
        delayMicroseconds(5000);
        digitalWrite(TEST_Y_STEP, LOW);
        delayMicroseconds(5000);
    }
    
    delay(1000);
    
    // ========== 测试5: 激光闪烁3次 ==========
    for (int i = 0; i < 3; i++) {
        digitalWrite(TEST_LASER, HIGH);
        delay(500);
        digitalWrite(TEST_LASER, LOW);
        delay(500);
    }
    
    // 禁用电机（高电平禁用）
    digitalWrite(TEST_EN, HIGH);
    
    // 测试完成，进入死循环
    while(1) {
        delay(1000);
    }
}

#endif

void setup() {
#if AUTO_TEST_MODE
    // 自动测试模式：直接测试电机，不启动GRBL
    autoTestMotors();
#else
    // 正常模式：启动GRBL
    grbl_init();
#endif
}

void loop() {
#if !AUTO_TEST_MODE
    run_once();
#endif
}
