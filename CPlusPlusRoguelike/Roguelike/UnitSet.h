#pragma once
#include "Unit.h"
#include <unordered_set>
#include <iterator>

namespace Roguelike {
	class Unit;
	template<int maxSize>
	class UnitSet {
	public:
		UnitSet() {
			count = 0;
		}

		bool Add(const Unit unit) {
			if (count == length) return false;
			set[count++] = unit;
			Remove(0);
			return true;
		}
		void Remove(const int unit);

	private:
		Unit set[maxSize];
		const int length = maxSize;
		int count;
	};
}
