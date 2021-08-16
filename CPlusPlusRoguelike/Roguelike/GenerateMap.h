#pragma once
#include "GameManager.h"
#include "Utility.h"

namespace Roguelike::Generation {
	class Generator {
	public:
		GameManager& GameManager;

		Generator(Roguelike::GameManager& gameManager);

		void Generate();

	private:
		void GenerateRoom(const Vector2& origin);
		void GeneratePath(const Vector2& pos1, const Vector2& pos2);
	};
}
