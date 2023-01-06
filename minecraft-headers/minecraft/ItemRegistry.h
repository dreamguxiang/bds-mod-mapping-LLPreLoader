#pragma once

#include "../Global.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include "HashedString.h"
#include "Memory.h"
#include "ItemTag.h"

class ItemRegistry{
public:
	MCAPI static std::vector<class SharedPtr<class Item>> mItemRegistry;

	struct ItemAlias{
		HashedString alias;
		char padding[120];
	};
	MCAPI struct std::pair<class HashedString, int> getNameFromAlias(class HashedString const&, int) const;

};