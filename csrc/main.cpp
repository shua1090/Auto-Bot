#include "pch.hpp"
#include "helpers.hpp"
#include "motor.hpp"

int main()
{   
    wiringPiSetup();

    Motor left(P11, P13, P15);
    left.drive();
    delay(1000);
    left.stop();
}
