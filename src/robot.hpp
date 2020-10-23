#ifndef ROBOT_H
#define ROBOT_H

#include "main.h"
#include "ports.hpp"

namespace workshop {
    struct Robot {
        pros::Motor driveLeftFront;
        pros::Motor driveRightFront;
        pros::Motor driveLeftBack;
        pros::Motor driveRightBack;

        Robot() : driveLeftFront(PORT_DRIVE_LEFT_FRONT), driveRightFront(PORT_DRIVE_RIGHT_FRONT), driveLeftBack(PORT_DRIVE_LEFT_BACK), driveRightBack(PORT_DRIVE_RIGHT_BACK) { }
    };
}

#endif /* ROBOT_H */
