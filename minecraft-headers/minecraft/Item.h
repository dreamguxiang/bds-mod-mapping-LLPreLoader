#pragma once
#include "../Global.h"
#include <string>

class Item {
public:
	char padding[552];

//	virtual ~Item() {}
	MCAPI std::string const& getFullItemName() const;
};
