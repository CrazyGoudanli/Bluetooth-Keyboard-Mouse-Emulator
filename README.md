# M5Stamp Control Air TV Keyboard & Gyro Mouse Emulator

# M5Stamp Control Air TV 键盘与陀螺仪鼠标模拟器

## English

This project turns an **M5Stamp Control Air TV version** device into a USB/Bluetooth HID keyboard and mouse emulator.

The main improvement in this version is mouse control: the original firmware moved the mouse with the arrow keys, which was slow and awkward for continuous movement. This version replaces that with **gyro / motion-based mouse control**, so the cursor can be moved by tilting or moving the device instead of repeatedly pressing direction keys.

### Key Features

- **USB HID + Bluetooth HID** keyboard and mouse emulation.
- **Keyboard / Mouse mode switching** with the GO / BtnA button.
- **Motion-controlled mouse movement** using the device IMU / gyro-style control.
- **Improved mouse usability** compared with arrow-key movement.
- **Keyboard mode** keeps the normal device key behavior.
- **Mouse buttons**:
  - Enter / OK: left click
  - `\\`: right click

### Supported Device

- **M5Stamp Control Air TV version**

### Usage

1. Power on the device.
2. Select USB or Bluetooth mode when prompted.
3. Use the GO / BtnA button to switch between keyboard mode and mouse mode.
4. In mouse mode, move the cursor with gyro / motion control instead of arrow keys.
5. Use Enter / OK for left click and `\\` for right click.

### Firmware

A ready-to-copy firmware binary may be provided as:

```text
cardputer-adv-imu-keyboard-mouse.bin
```

You can flash the firmware with your preferred ESP32-S3 flashing tool, PlatformIO, or M5Burner-style workflow if adapted for your device.

---

## 中文

这个项目可以把 **M5Stamp Control Air TV 版本** 设备变成一个 USB / 蓝牙 HID 键盘与鼠标模拟器。

这个版本的重点优化是鼠标控制方式：原版固件使用方向键控制鼠标移动，操作比较慢，连续移动也不顺手。现在改成了 **陀螺仪 / 体感方式控制鼠标**，可以通过倾斜或移动设备来控制光标，不再需要反复按方向键。

### 主要功能

- 支持 **USB HID + 蓝牙 HID** 键盘和鼠标模拟。
- 支持通过 GO / BtnA 按钮在键盘模式和鼠标模式之间切换。
- 使用设备 IMU / 陀螺仪式体感控制鼠标移动。
- 相比方向键移动鼠标，操作更自然、更快。
- 键盘模式保留设备原本按键输入逻辑。
- 鼠标按键：
  - Enter / OK：鼠标左键
  - `\\`：鼠标右键

### 支持设备

- **M5Stamp Control Air TV 版本**

### 使用方法

1. 打开设备电源。
2. 启动时选择 USB 或蓝牙模式。
3. 使用 GO / BtnA 按钮切换键盘模式和鼠标模式。
4. 在鼠标模式下，通过陀螺仪 / 体感方式移动光标，不再使用方向键慢慢移动。
5. 使用 Enter / OK 作为鼠标左键，`\\` 作为鼠标右键。

### 固件

可直接拷贝或烧录的固件文件可以使用：

```text
cardputer-adv-imu-keyboard-mouse.bin
```

你可以使用 ESP32-S3 烧录工具、PlatformIO，或者适配后的 M5Burner 类流程将固件写入设备。
