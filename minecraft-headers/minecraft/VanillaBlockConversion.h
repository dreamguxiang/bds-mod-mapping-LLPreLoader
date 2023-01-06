#pragma once

#include <string>

#include "Memory.h"
#include "BlockLegacy.h"

namespace VanillaBlockConversion {
	__declspec(dllimport) int getBlockTypeLegacyIdFromName(std::string const&);
	__declspec(dllimport) Block* tryGetLegacyState(unsigned int, unsigned int);
};
