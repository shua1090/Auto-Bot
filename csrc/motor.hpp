#ifndef MOTOR_H
#define MOTOR_H

#include <wiringPi.h>

class Motor {
private:
    int mEnable, mPin1, mPin2;
    int mSpeed;
public:
    Motor(int enable, int pin1, int pin2);
    ~Motor() = default;

    int getSpeed() const;
    void setSpeed(int speed);

    void drive() const;
    void stop(bool) const;
};

#endif