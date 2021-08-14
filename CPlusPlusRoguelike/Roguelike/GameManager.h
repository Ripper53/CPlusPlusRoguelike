#pragma once

namespace Roguelike {
	class GameManager {
	public:
		enum class Tile { Wall, Ground };
		Tile* Tiles;
		const int Width, Height;

		GameManager(int width, int height);
		~GameManager();

		Tile Get(int x, int y);
		void Set(Tile tile, int x, int y);
	};
}
