#include "pch.h"
#include "UnitSet.h"

namespace Roguelike {
	template<int maxSize>
	void UnitSet<maxSize>::Remove(const int index) {
		set[index] = set[--count];
	}

}
