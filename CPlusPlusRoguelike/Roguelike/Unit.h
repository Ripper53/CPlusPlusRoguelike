#pragma once
#include "Utility.h"

namespace Roguelike {
	class Unit {
	public:
		const char Sprite;
		Vector2 Position;

		Unit();
		Unit(char sprite, Vector2 position);
	};
}
