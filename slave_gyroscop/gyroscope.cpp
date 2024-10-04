#include "gyroscope.h"
#include "MPU6050.h"

MPU6050 mpu;

void Gyroscope::begin() {
    mpu.initialize();
}

void Gyroscope::getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz) {
    mpu.getMotion6(ax, ay, az, gx, gy, gz);
}
int Gyroscope::calculateDirection(int16_t ax, int16_t ay, int16_t az) {
    // Define your dead zone threshold
    const int16_t deadZoneThreshold = 9000;
    // Define your minimum change threshold
    const int16_t minChangeThreshold = 5000;

    int direction = 0; // Initialize direction to no movement

    // Check if the absolute value of ax is greater than the dead zone threshold
    if (abs(ax) > deadZoneThreshold && abs(ax) > minChangeThreshold) {
        // Determine direction based on the sign of ax
        direction = (ax > 0) ? 2 : 1; // Forward or Backward
    }

    // Check if the absolute value of ay is greater than the dead zone threshold
    if (abs(ay) > deadZoneThreshold && abs(ay) > minChangeThreshold) {
        // Determine direction based on the sign of ay
        int leftOrRight = (ay > 0) ? 4 : 3; // Left or Right
        // Prioritize left or right movements over forward or backward movements
        if (abs(ay) > abs(ax)) {
            direction = leftOrRight;
        }
    }

    return direction;
}

