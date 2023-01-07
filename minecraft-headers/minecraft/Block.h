#pragma once
#include "../Global.h"
#include "BlockLegacy.h"
#include "CompoundTag.h"

class Block {
public:
	MCAPI class BlockLegacy const& getLegacyBlock() const;

	MCAPI float getDestroySpeed() const;

	virtual ~Block() {}

	unsigned short data;
	BlockLegacy* blockLegacy;

	char filler2[132];
	CompoundTag tag;//160
};

static_assert(offsetof(Block, tag) == 160);
