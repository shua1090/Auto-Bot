#include "pch.hpp"
#include "helpers.hpp"
#include "robot.hpp"

int main() {   
    wiringPiSetup();

    Motor left(P11, P13, P15);
    // Motor right(P18, P12, P16);

    const int min = 20;
    const int max = 100;

}
