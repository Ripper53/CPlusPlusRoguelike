#include "pch.h"
#include <random>	
#include "GenerateMap.h"
#include "GameManager.h"
#include "Utility.h"

namespace Roguelike::Generation {
	Generator::Generator(Roguelike::GameManager& gameManager) : GameManager(gameManager) {
		
	}
	void Generator::Generate() {
		std::vector<Vector2> pos = std::vector<Vector2>();

		for (int y = 0; y < GameManager.Height; y++) {
			for (int x = 0; x < GameManager.Width; x++) {
				GameManager.Set(GameManager::Tile::Wall, x, y);
			}
		}

		for (int i = 0; i < 4; i++) {
			Vector2 p = { rand() % GameManager.Width, rand() % GameManager.Height };
			pos.push_back(p);
			GenerateRoom(p);
		}

		for (int i = 1; i < pos.size(); i++) {
			Vector2 pos1 = pos[i - 1], pos2 = pos[i];
			GeneratePath(pos1, pos2);
		}
	}
	void Generator::GenerateRoom(const Vector2& origin) {
		int w = (rand() % 8) + 4, h = (rand() % 8) + 4;
		for (int y = 0; y < h; y++) {
			if ((origin.y + y) >= GameManager.Height) break;
			for (int x = 0; x < w; x++) {
				if ((origin.x + x) >= GameManager.Width) break;
				GameManager.Set(GameManager::Tile::Ground, origin.x + x, origin.y + y);
			}
		}
	}
	void Generator::GeneratePath(const Vector2& pos1, const Vector2& pos2) {
		Vector2 p = { pos1.x, pos1.y };
		while (p != pos2) {
			if (p.x < pos2.x) {
				p.x += 1;
			} else if (p.x > pos2.x) {
				p.x -= 1;
			} else if (p.y < pos2.y) {
				p.y += 1;
			} else {
				p.y -= 1;
			}
			GameManager.Set(GameManager::Tile::Ground, p.x, p.y);
		}
	}
}
