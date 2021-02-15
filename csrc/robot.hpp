#ifndef ROBOT_H
#define ROBOT_H

#include "pch.hpp"
#include "helpers.hpp"
#include "motor.hpp"

class Robot {
private:
    Motor* mLhs, *mRhs;
public:
    Robot(Motor& lhs, Motor& rhs);
    Robot() = default;
    ~Robot() = default;
};

#endif