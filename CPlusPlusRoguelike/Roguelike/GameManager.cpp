#include "pch.h"
#include "GameManager.h"

namespace Roguelike {
	GameManager::GameManager(int width, int height) : Width(width), Height(height) {
		this->Tiles = new Tile[width * height];
	}
	GameManager::~GameManager() {
		delete[] this->Tiles;
	}

	GameManager::Tile GameManager::Get(int x, int y) {
		return this->Tiles[x + (this->Width * y)];
	}

	void GameManager::Set(GameManager::Tile tile, int x, int y) {
		this->Tiles[x + (this->Width * y)] = tile;
	}

}
