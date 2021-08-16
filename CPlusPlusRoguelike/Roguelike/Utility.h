#pragma once

namespace Roguelike {
	struct Vector2 {
	public:
		int x, y;

		bool operator==(const Vector2 vec) const;
		bool operator!=(const Vector2 vec) const;
	};
}
