#include "pch.hpp"
#include "helpers.hpp"
// #include "motor.hpp"

int main()
{   
    wiringPiSetup();

    pinMode(P11, OUTPUT);
    pinMode(P13, OUTPUT);
    pinMode(P15, OUTPUT);

    softPwmWrite(P11, 75);
    digitalWrite(P13, HIGH);
    digitalWrite(P15, LOW);
    delay(1000);
    softPwmWrite(P11, 0);

    // Motor left(P11, P13, P15);
    // left.drive();
    // left.stop();
}
