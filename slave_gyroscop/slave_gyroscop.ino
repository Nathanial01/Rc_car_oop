#include <Arduino.h>
#include "Src.h"

int previousDirection = 0;

void setup() {
    Serial.begin(38400);
    while (!Serial);

    bluetooth.begin(38400); // Initialize software serial for Bluetooth module
    gyroscope.begin();
     Serial.println("innwcated");
}

void loop() {
   Serial.println("0");
    delay(100);
    int16_t ax, ay, az, gx, gy, gz; // Declare az and gz
    gyroscope.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  // Get motion data from the gyroscope

    int direction = gyroscope.calculateDirection(ax, ay, az);  // Calculate direction based on the motion data

    if (direction != previousDirection) {
        switch (direction) {
            case 2:
                bluetooth.println("F"); // Send "F" for forward
                Serial.println("1");
                break;
            case 1:
                bluetooth.println("B"); // Send "B" for backward
                Serial.println("2");
                break;
            case 3:
                bluetooth.println("L"); // Send "L" for left
                Serial.println("3");
                break;
            case 4:
                bluetooth.println("R"); // Send "R" for right
                Serial.println("4");
                break;
            default:
                bluetooth.println("S"); // Send "S" for stop if no movement
                Serial.println("0");
                break;
        }
        previousDirection = direction; // Update previous direction
    }
  
    delay(100);
}
