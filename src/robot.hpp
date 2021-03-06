#ifndef ROBOT_H
#define ROBOT_H

#include "main.h"
#include "ports.hpp"

namespace workshop {
    constexpr int16_t INTAKE_VOLTAGE = 8000;

    // RPM
    constexpr int16_t LIFT_VELOCITY = 80;

    struct Robot {
        pros::Motor driveLeftFront;
        pros::Motor driveRightFront;
        pros::Motor driveLeftBack;
        pros::Motor driveRightBack;

        pros::Motor intakeRollerLeft;
        pros::Motor intakeRollerRight;

        pros::Motor liftLeft;
        pros::Motor liftRight;

        Robot()
            // this->driveLeftFront = pros::Motor(PORT_DRIVE_LEFT_FRONT, DRIVE_LEFT_FRONT_REVERSED)
            // this is called a "member initializer list"
            // NOTE -- reason we don't need to prefix constants with namespace
            // is because we are in the context of the same namespace
            : driveLeftFront(PORT_DRIVE_LEFT_FRONT, DRIVE_LEFT_FRONT_REVERSED)
            , driveRightFront(PORT_DRIVE_RIGHT_FRONT, DRIVE_RIGHT_FRONT_REVERSED)
            , driveLeftBack(PORT_DRIVE_LEFT_BACK, DRIVE_LEFT_BACK_REVERSED)
            , driveRightBack(PORT_DRIVE_RIGHT_BACK, DRIVE_RIGHT_BACK_REVERSED)
            , intakeRollerLeft(PORT_INTAKE_ROLLER_LEFT, INTAKE_ROLLER_LEFT_REVERSED)
            , intakeRollerRight(PORT_INTAKE_ROLLER_RIGHT, INTAKE_ROLLER_RIGHT_REVERSED)
            , liftLeft(PORT_LIFT_LEFT, LIFT_LEFT_REVERSED)
            , liftRight(PORT_LIFT_RIGHT, LIFT_RIGHT_REVERSED)
        {
            this->liftLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            this->liftRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        }

        void someRobotFunction();
    };
}

#endif /* ROBOT_H */
