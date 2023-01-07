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
	struct ItemAlias{
		HashedString alias;
		char padding[120];
	};
	MCAPI struct std::pair<class HashedString, int> getNameFromAlias(class HashedString const&, int) const;
	MCAPI class WeakPtr<class Item> getItem(short);
	
};

class ItemRegistryRef {
public:
	MCAPI class std::shared_ptr<class ItemRegistry> _lockRegistry() const;
	
	MCAPI class WeakPtr<class Item> getItem(short) const;
};