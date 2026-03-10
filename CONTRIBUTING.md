# 贡献指南

感谢你考虑为本项目做出贡献！🎉

---

## 🤝 如何贡献

### 报告 Bug

如果你发现了 Bug，请：

1. 检查 [Issues](https://github.com/Carl-debug2025/esp32-grbl-laser/issues) 中是否已有相同问题
2. 如果没有，创建新 Issue，包含：
   - 清晰的标题
   - 复现步骤
   - 预期行为
   - 实际行为
   - 截图（如果有帮助）
   - 你的环境信息（固件版本、浏览器版本等）

### 提交代码

1. Fork 本仓库
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 提交 Pull Request

---

## 📝 代码规范

### C/C++ 代码

- 遵循 [Grbl 代码风格](https://github.com/gnea/grbl/wiki/Code-Style)
- 函数名使用 snake_case
- 常量使用大写 SNAKE_CASE
- 添加必要注释

```c
// 正确示例
void set_spindle_speed(uint32_t rpm) {
    spindle_set_rpm(rpm);
}

// 错误示例
void setSpindleSpeed(uint32_t RPM) {
    spindle_SetRPM(RPM);
}
```

### HTML/JavaScript

- 使用 4 空格缩进
- 变量名使用 camelCase
- 函数名使用 camelCase
- 常量使用大写 SNAKE_CASE

```javascript
// 正确示例
const MAX_POWER = 1000;

function sendGCode(command) {
    // ...
}
```

---

## 📋 提交信息规范

使用清晰的提交信息：

```
<type>(<scope>): <subject>

<body>

<footer>
```

### Type 类型

- `feat`: 新功能
- `fix`: Bug 修复
- `docs`: 文档更新
- `style`: 代码格式（不影响功能）
- `refactor`: 重构
- `perf`: 性能优化
- `test`: 测试相关
- `chore`: 构建/工具相关

### 示例

```
feat(firmware): 添加 Z 轴支持

- 新增 Z 轴引脚定义
- 更新运动规划算法
- 更新 README 文档

Closes #123
```

---

## ⚖️ 许可证

通过提交代码，你同意你的贡献将遵循 GPLv3 许可证。

这意味着：
- 你的代码将被开源
- 任何人都可以使用、修改和分发
- 修改后的版本必须保持 GPLv3 许可证

---

## 🙏 感谢

感谢所有贡献者的付出！

---

**Happy Contributing! 🚀**
