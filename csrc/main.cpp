#include "pch.hpp"
#include "helpers.hpp"
// #include "motor.hpp"

int main()
{   
    wiringPiSetup();

    Pin enable = P11;
    Pin pin1 = P13;
    Pin pin2 = P15;

    pinMode(enable, OUTPUT);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);

    digitalWrite(enable, HIGH);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    delay(1000);
    digitalWrite(enable, LOW);
}
