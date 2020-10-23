#include "main.h"
#include "ports.hpp"
#include "robot.hpp"
#include "controls.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

void op_lift(workshop::Robot& robot, pros::Controller& controller) {
	using namespace workshop;

	if (controller.get_digital(controls::LIFT_UP)) {
		robot.liftLeft.move_velocity(LIFT_VELOCITY);
		robot.liftRight.move_velocity(LIFT_VELOCITY);
	}
	else if (controller.get_digital(controls::LIFT_DOWN)) {
		robot.liftLeft.move_velocity(-LIFT_VELOCITY);
		robot.liftRight.move_velocity(-LIFT_VELOCITY);
	}
	else {
		robot.liftLeft.move_velocity(0);
		robot.liftRight.move_velocity(0);
	}
}

void op_drive(workshop::Robot& robot, pros::Controller& controller) {
	int left = controller.get_analog(ANALOG_LEFT_Y);
	int right = controller.get_analog(ANALOG_RIGHT_Y);

	robot.driveLeftFront.move(left);
	robot.driveLeftBack.move(left);

	robot.driveRightFront.move(right);
	robot.driveRightBack.move(right);
}

void op_intake(workshop::Robot& robot, pros::Controller& controller) {
	using namespace workshop;

	if (controller.get_digital(controls::INTAKE_SPIN_IN)) {
		robot.intakeRollerLeft.move_voltage(-INTAKE_VOLTAGE);
		robot.intakeRollerRight.move_voltage(-INTAKE_VOLTAGE);
	}
	else if (controller.get_digital(controls::INTAKE_SPIN_OUT)) {
		robot.intakeRollerLeft.move_voltage(INTAKE_VOLTAGE);
		robot.intakeRollerRight.move_voltage(INTAKE_VOLTAGE);
	}
	else {
		robot.intakeRollerLeft.move_voltage(0);
		robot.intakeRollerRight.move_voltage(0);
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	// unlike in Java, this will automatically call the default constructor
	// therefore, this is not null as you may think
	workshop::Robot robot;

	while (true) {
		op_drive(robot, master);
		op_intake(robot, master);
		op_lift(robot, master);

		pros::delay(20);
	}
}
