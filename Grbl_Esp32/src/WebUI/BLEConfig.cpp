/*
  BLEConfig.cpp - BLE (Bluetooth Low Energy) for ESP32-C3
  
  使用 Nordic UART Service (NUS) 协议
  兼容大多数 BLE 串口应用和 Web Bluetooth API
*/

#include "../Grbl.h"

#ifdef ESP32_C3

#include "BLEConfig.h"

namespace WebUI {

BLEConfig ble_config;

// 静态成员初始化
BLEServer* BLEConfig::pServer = nullptr;
BLECharacteristic* BLEConfig::pTxCharacteristic = nullptr;
BLECharacteristic* BLEConfig::pRxCharacteristic = nullptr;
bool BLEConfig::deviceConnected = false;
bool BLEConfig::oldDeviceConnected = false;
String BLEConfig::rxBuffer = "";

// BLE 服务器回调类
class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        BLEConfig::deviceConnected = true;
        grbl_send(CLIENT_SERIAL, "[MSG:BLE Connected]\r\n");
    }

    void onDisconnect(BLEServer* pServer) {
        BLEConfig::deviceConnected = false;
        grbl_send(CLIENT_SERIAL, "[MSG:BLE Disconnected]\r\n");
    }
};

// 让 MyServerCallbacks 可以访问私有成员
class BLEConfig;

// BLE 特征回调类 - 接收数据
class MyCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic) {
        std::string rxValue = pCharacteristic->getValue();
        
        if (rxValue.length() > 0) {
            // 将接收到的数据添加到缓冲区
            for (int i = 0; i < rxValue.length(); i++) {
                BLEConfig::rxBuffer += rxValue[i];
            }
            
            // 防止缓冲区过大（限制在4KB）
            if (BLEConfig::rxBuffer.length() > 4096) {
                BLEConfig::rxBuffer = BLEConfig::rxBuffer.substring(BLEConfig::rxBuffer.length() - 2048);
            }
        }
    }
};

void BLEConfig::begin() {
    grbl_send(CLIENT_SERIAL, "[MSG:BLE Starting...]\r\n");
    
    // 创建 BLE 设备
    BLEDevice::init("GRBL_ESP32C3");
    
    // 创建 BLE 服务器
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());
    
    // 创建 BLE 服务 (Nordic UART Service)
    BLEService* pService = pServer->createService(SERVICE_UUID);
    
    // 创建 TX 特征 (ESP32 -> 手机)
    pTxCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_TX,
        BLECharacteristic::PROPERTY_NOTIFY
    );
    pTxCharacteristic->addDescriptor(new BLE2902());
    
    // 创建 RX 特征 (手机 -> ESP32)
    pRxCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_WRITE_NR
    );
    pRxCharacteristic->setCallbacks(new MyCallbacks());
    
    // 启动服务
    pService->start();
    
    // 开始广播
    BLEAdvertising* pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
    
    grbl_send(CLIENT_SERIAL, "[MSG:BLE Started - Name: GRBL_ESP32C3]\r\n");
}

void BLEConfig::end() {
    if (pServer != nullptr) {
        BLEDevice::deinit(true);
        pServer = nullptr;
    }
}

void BLEConfig::handle() {
    // 如果设备断开，重新开始广播
    if (!deviceConnected && oldDeviceConnected) {
        delay(500);  // 给蓝牙栈一点时间
        pServer->startAdvertising();
        grbl_send(CLIENT_SERIAL, "[MSG:BLE Advertising...]\r\n");
        oldDeviceConnected = deviceConnected;
    }
    
    // 如果设备刚连接
    if (deviceConnected && !oldDeviceConnected) {
        oldDeviceConnected = deviceConnected;
    }
}

bool BLEConfig::isConnected() {
    return deviceConnected;
}

void BLEConfig::sendData(const char* data) {
    if (deviceConnected && pTxCharacteristic != nullptr) {
        pTxCharacteristic->setValue((uint8_t*)data, strlen(data));
        pTxCharacteristic->notify();
    }
}

bool BLEConfig::hasData() {
    return rxBuffer.length() > 0;
}

String BLEConfig::readData() {
    String data = rxBuffer;
    rxBuffer = "";
    return data;
}

}  // namespace WebUI

#endif  // ESP32_C3

