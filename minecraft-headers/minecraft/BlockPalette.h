#pragma once

#include <string>
#include <iostream>
#include "Block.h"

class BlockPalette {
public:
	MCAPI class BlockLegacy const* getBlockLegacy(std::string const&) const;

	MCAPI class Block const& getBlock(class CompoundTag const&) const;
	//__declspec(dllimport) const Block *getBlock(BlockSerializationId const &) const;
	MCAPI class Block const& getBlock(unsigned int const&) const;

	size_t getNumBlockRuntimeIds() const {
		auto v3 = *((__int64*)this + 14);
		//std::cout << "v3: " << v3 << std::endl;
		auto v4 = *((__int64*)this + 15);
		//std::cout << "v4: " << v4 << std::endl;
		return (v4 - v3) >> 3;
	 }
};
