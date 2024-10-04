#ifndef SRC_H
#define SRC_H

// Define your desired RX and TX pins for Bluetooth communication
#define RX_PIN 1
#define TX_PIN 0

#include "BluetoothUtils.h" // Include the header file for your Bluetooth utility functions
#include "Gyroscope.h" // Include the header file for your gyroscope library

extern BluetoothUtils btUtils; // Declare the Bluetooth utility object
extern Gyroscope gyroscope; // Declare the gyroscope object
extern SoftwareSerial bluetooth;// RX, TX
#endif
