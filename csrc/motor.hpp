#ifndef MOTOR_H
#define MOTOR_H

#include "pch.hpp"
#include "helpers.hpp"

class Motor {
private:
    Pin mEnable, mPin1, mPin2;
    int* mDefaultSpeed;
public:
    Motor() = default;
    Motor(Pin enable, Pin pin1, Pin pin2);
    Motor(Pin enable, Pin pin1, Pin pin2, int& defSpeed);
    ~Motor();

    void drive(bool dir) const;
    void drive(bool dir, int speed) const;
    void stop() const;
};

Motor::Motor(Pin enable, Pin pin1, Pin pin2) 
    : mEnable(enable), mPin1(pin1), mPin2(pin2) {
    pinMode(mEnable, OUTPUT);
    pinMode(mPin1, OUTPUT);
    pinMode(mPin2, OUTPUT);

    softPwmCreate(mEnable, 0, 100);
}

Motor::Motor(Pin enable, Pin pin1, Pin pin2, int& defSpeed)
    : Motor(enable, pin1, pin2) {
    mDefaultSpeed = &defSpeed;
}

Motor::~Motor() {
    softPwmWrite(mEnable, 0);
    softPwmStop(mEnable);
    digitalWrite(mPin1, LOW);
    digitalWrite(mPin2, LOW);
}

void Motor::drive(bool dir, int speed) const {
    softPwmWrite(mEnable, speed);
    digitalWrite(mPin1, dir);
    digitalWrite(mPin2, dir ^ 1);
}

void Motor::drive(bool dir) const {
    drive(dir, *mDefaultSpeed);
}

void Motor::stop() const {
    drive(0, 0);
}

#endif


// int getSpeed() const;
// void setSpeed(int speed);

// int Motor::getSpeed() const {
//     return mSpeed;
// }
// void Motor::setSpeed(int speed) {
//     mSpeed = speed;
// }


// void Motor::drive() const {
//     drive(*mSpeed);
// }