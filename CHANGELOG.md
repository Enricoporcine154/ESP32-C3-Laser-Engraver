# 更新日志

本项目的所有重要更改都将记录在此文件中。

格式基于 [Keep a Changelog](https://keepachangelog.com/zh-CN/1.0.0/)，
并且本项目遵循 [语义化版本](https://semver.org/lang/zh-CN/)。

---

## [Unreleased]

### 待添加
- Z 轴支持（可选）
- 自动对焦功能
- WebUI 界面优化
- WiFi 远程控制

---

## [1.0.0] - 2026-03-10

### 新增
- ✨ ESP32-C3FH4 芯片适配
- ✨ 一体化 PCB 设计（去模块化）
- ✨ Web 控制端（`G代码生成器.html`）
  - 基于 Web Bluetooth API 的 BLE 通信
  - 实时轨迹预览
  - 图像转 G 代码（LaserGRBL 算法）
  - 手动控制和状态监控
- ✨ 禁用硬限位功能（采用手动定位方案）
- ✨ 中文文档和教程

### 硬件
- 🔧 A4988 步进驱动集成（16 细分）
- 🔧 250-500mW 激光模块支持（PWM 控制）
- 🔧 工作范围：42×42mm
- 🔧 步进分辨率：106.67 steps/mm
- 🔧 最大速度：3000 mm/min

### 固件
- 🐛 修复 ESP32-C3 RMT/I2S 兼容性问题
- 🐛 修复禁用限位后的 Alarm 状态处理
- ⚡️ 优化运动参数（加速度 100 mm/s²）
- ⚡️ 电机永不断电（$1=255）

### 文档
- 📚 README.md（完整的快速开始指南）
- 📚 硬件设计文件说明
- 📚 贡献指南

### 来源声明
- 下位机固件基于 [Grbl_ESP32](https://github.com/bdring/Grbl_Esp32)
- 上位机算法参考 [LaserGRBL](https://github.com/arkypita/LaserGRBL)
- 感谢原作者的开源贡献

---

## 版本说明

- **[Unreleased]**: 开发中的功能
- **[1.0.0]**: 首个正式发布版本

---

## 升级指南

### 从早期版本升级到 1.0.0

1. 备份你的参数设置（使用 `$$` 命令导出）
2. 烧录新固件
3. 恢复参数设置（可选）
4. 清除 EEPROM（`$RST=$`）并重新配置

---

**[Unreleased]: https://github.com/Carl-debug2025/esp32-grbl-laser/compare/v1.0.0...HEAD**
**[1.0.0]: https://github.com/Carl-debug2025/esp32-grbl-laser/releases/tag/v1.0.0**
