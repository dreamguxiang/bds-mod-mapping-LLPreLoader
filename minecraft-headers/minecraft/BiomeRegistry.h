#pragma once

#include <functional>
#include "Biome.h"

class BiomeRegistry {
public:
	MCAPI class Biome* lookupById(int) const;

	MCAPI void forEachBiome(class std::function<void(class Biome&)>) const;
};
