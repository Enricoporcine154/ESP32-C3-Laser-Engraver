#pragma once

/*
  BLEConfig.h - BLE (Bluetooth Low Energy) for ESP32-C3
  
  ESP32-C3 不支持经典蓝牙，只支持 BLE
  使用 GATT 服务接收 G代码命令
*/

#ifdef ESP32_C3

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// BLE 服务和特征 UUID
#define SERVICE_UUID        "6e400001-b5a3-f393-e0a9-e50e24dcca9e"  // Nordic UART Service
#define CHARACTERISTIC_UUID_RX "6e400002-b5a3-f393-e0a9-e50e24dcca9e"  // 接收数据
#define CHARACTERISTIC_UUID_TX "6e400003-b5a3-f393-e0a9-e50e24dcca9e"  // 发送数据

namespace WebUI {

class BLEConfig {
public:
    static void begin();
    static void end();
    static void handle();
    static bool isConnected();
    static void sendData(const char* data);
    static bool hasData();
    static String readData();
    
// 这些成员需要被回调类访问，所以设为public
    static BLEServer* pServer;
    static BLECharacteristic* pTxCharacteristic;
    static BLECharacteristic* pRxCharacteristic;
    static bool deviceConnected;
    static bool oldDeviceConnected;
    static String rxBuffer;
};

extern BLEConfig ble_config;

}  // namespace WebUI

#endif  // ESP32_C3

