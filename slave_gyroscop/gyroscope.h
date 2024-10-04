#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <Arduino.h>

class Gyroscope {
public:
    void begin();
    void getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
    int calculateDirection(int16_t ax, int16_t ay, int16_t az);
};

#endif
