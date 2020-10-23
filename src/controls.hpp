#ifndef CONTROLS_H
#define CONTROLS_H

#include "main.h"

namespace workshop {
	namespace controls {
		constexpr pros::controller_digital_e_t INTAKE_SPIN_OUT = pros::E_CONTROLLER_DIGITAL_R2;
		constexpr pros::controller_digital_e_t INTAKE_SPIN_IN = pros::E_CONTROLLER_DIGITAL_R1;

		constexpr pros::controller_digital_e_t LIFT_UP = pros::E_CONTROLLER_DIGITAL_L1;
		constexpr pros::controller_digital_e_t LIFT_DOWN = pros::E_CONTROLLER_DIGITAL_L2;
	}
}

#endif /* CONTROLS_H */
