#include "pch.h"
#include <random>	
#include "GameManager.h"

namespace Roguelike::Generation {
	void Generate(GameManager* gameManager) {
		for (int y = 0; y < gameManager->Height; y++) {
			for (int x = 0; x < gameManager->Width; x++) {
				gameManager->Set((GameManager::Tile)(rand() % 2), x, y);
			}
		}
	}
}
