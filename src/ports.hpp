#ifndef PORTS_H
#define PORTS_H

#include "stdint.h"

namespace workshop {
	constexpr int8_t PORT_DRIVE_LEFT_FRONT = 1;
	constexpr int8_t PORT_DRIVE_RIGHT_FRONT = 2;
	constexpr int8_t PORT_DRIVE_LEFT_BACK = 3;
	constexpr int8_t PORT_DRIVE_RIGHT_BACK = 4;

	constexpr bool DRIVE_LEFT_FRONT_REVERSED = false;
	constexpr bool DRIVE_RIGHT_FRONT_REVERSED = true;
	constexpr bool DRIVE_LEFT_BACK_REVERSED = false;
	constexpr bool DRIVE_RIGHT_BACK_REVERSED = true;
}

#endif /* PORTS_H */
