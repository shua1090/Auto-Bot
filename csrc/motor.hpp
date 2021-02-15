#ifndef MOTOR_H
#define MOTOR_H

#include "pch.hpp"
#include "helpers.hpp"

class Motor {
private:
    Pin mEnable, mPin1, mPin2;
    int mSpeed;
public:
    Motor() = default;
    Motor(Pin enable, Pin pin1, Pin pin2);
    ~Motor() = default;

    int getSpeed() const;
    void setSpeed(int speed);

    void drive() const;
    void stop(bool full=false) const;
};

Motor::Motor(Pin enable, Pin pin1, Pin pin2) 
: mEnable(enable), mPin1(pin1), mPin2(pin2) {
    pinMode(mEnable, OUTPUT);
    pinMode(mPin1, OUTPUT);
    pinMode(mPin2, OUTPUT);

    mSpeed = 75;
    assert(softPwmCreate(mEnable, mSpeed, 100) == 0);
}

int Motor::getSpeed() const {
    return mSpeed;
}
void Motor::setSpeed(int speed) {
    mSpeed = speed;
}

void Motor::drive() const {
    softPwmWrite(mEnable, mSpeed);
    digitalWrite(mPin1, HIGH);
    digitalWrite(mPin2, LOW);
}

void Motor::stop(bool full) const {
    softPwmWrite(mEnable, 0);
    softPwmStop(mEnable);
    if (full) {
        digitalWrite(mPin1, LOW);
        digitalWrite(mPin2, LOW);
    }
}

#endif