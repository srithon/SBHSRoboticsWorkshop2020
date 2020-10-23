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

        Robot()
            // this->driveLeftFront = pros::Motor(PORT_DRIVE_LEFT_FRONT, DRIVE_LEFT_FRONT_REVERSED)
            // this is called a "member initializer list"
            // NOTE -- reason we don't need to prefix constants with namespace
            // is because we are in the context of the same namespace
            : driveLeftFront(PORT_DRIVE_LEFT_FRONT, DRIVE_LEFT_FRONT_REVERSED)
            , driveRightFront(PORT_DRIVE_RIGHT_FRONT, DRIVE_RIGHT_FRONT_REVERSED)
            , driveLeftBack(PORT_DRIVE_LEFT_BACK, DRIVE_LEFT_BACK_REVERSED)
            , driveRightBack(PORT_DRIVE_RIGHT_BACK, DRIVE_RIGHT_BACK_REVERSED)
        { }
    };
}

#endif /* ROBOT_H */
