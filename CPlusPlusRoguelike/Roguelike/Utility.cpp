#include "pch.h"
#include "Utility.h"

namespace Roguelike {
	bool Vector2::operator==(const Vector2 vec) const {
		return x == vec.x && y == vec.y;
	}
	bool Vector2::operator!=(const Vector2 vec) const {
		return x != vec.x || y != vec.y;
	}
}
