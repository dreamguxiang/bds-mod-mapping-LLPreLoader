#pragma once

#include "HashedString.h"

struct Block;
#include "../Global.h"

class BlockLegacy {
public:

	std::string descriptionId;
	HashedString baseName;
	std::string namespaceName;
	HashedString fullName;

	char padding[120];
	char unknown;
	char opacity;
	char brightness;
	int flameEncouragement;
	int flammability;
	bool lavaFlammable;
	float hardness;
	float blastResistance;
	char padding2[16];
	float friction;
	MCAPI short getBlockItemId() const;
	
	const short getBlockID() const {
		return getBlockItemId();
	}

	std::string getFullName() const {
		return fullName.str;
	}

	MCAPI float getDestroySpeed() const;

	virtual ~BlockLegacy();
	virtual class Block const& getStateFromLegacyData(unsigned short) const;

};

static_assert(offsetof(BlockLegacy, opacity) == 289);
