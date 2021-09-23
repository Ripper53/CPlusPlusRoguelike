#pragma once
#include "UnitSet.h"

namespace Roguelike {
	enum class Tile { Wall, Ground };
	template <int W, int H>
	class GameManager {
	public:
		Tile Tiles[W * H];
		const int Width = W, Height = H;
		UnitSet<255> Units;

		GameManager() : Units(UnitSet<255>()) {

		}

		Tile Get(const int x, const int y) const {
			return Tiles[x + (Width * y)];
		}
		void Set(const Tile tile, const int x, const int y) {
			Tiles[x + (Width * y)] = tile;
		}

	private:
		const int length = W * H;
	};
}
