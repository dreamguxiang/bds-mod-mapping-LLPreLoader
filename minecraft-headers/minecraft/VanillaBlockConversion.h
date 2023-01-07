#pragma once

#include <string>

#include "Memory.h"
#include "BlockLegacy.h"

namespace VanillaBlockConversion {
	MCAPI int getBlockTypeLegacyIdFromName(std::string const&);
	MCAPI Block* tryGetLegacyState(unsigned int, unsigned int);
};
