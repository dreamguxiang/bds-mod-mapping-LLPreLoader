#pragma once
#include <functional>
#include "BlockLegacy.h"
#include "HashedString.h"
#include "Memory.h"

class BlockTypeRegistry{
public:
	MCAPI static void forEachBlock(class std::function<bool(class BlockLegacy const&)>);

	MCAPI static class WeakPtr<class BlockLegacy> lookupByName(class HashedString const&, bool);
};
