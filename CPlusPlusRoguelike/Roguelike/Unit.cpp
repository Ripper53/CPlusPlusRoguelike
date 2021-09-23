#include "pch.h"
#include "Unit.h"

namespace Roguelike {
	Unit::Unit() : Sprite('@') {
		Position = Vector2(0, 0);
	}
	Unit::Unit(char sprite, Vector2 position) : Sprite(sprite) {
		Position = position;
	}
}
