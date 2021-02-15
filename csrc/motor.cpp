#include "motor.hpp"

Motor::Motor(int enable, int pin1, int pin2)
    : mEnable(enable), mPin1(pin1), mPin2(pin2) {}

int Motor::getSpeed() const {
    return mSpeed;
}
void Motor::setSpeed(int speed) {
    mSpeed = speed;
}

void Motor::drive() const {
    digitalWrite(mEnable, HIGH);
    digitalWrite(mPin1, HIGH);
    digitalWrite(mPin2, LOW);
}

void Motor::stop(bool full) const {
    digitalWrite(mEnable, LOW);
    if (full) {
        digitalWrite(mPin1, LOW);
        digitalWrite(mPin2, LOW);
    }
}