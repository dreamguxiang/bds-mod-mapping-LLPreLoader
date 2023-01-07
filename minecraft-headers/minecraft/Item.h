#pragma once
#include "../Global.h"
#include <string>

class Item {
public:
	char padding[576];

//	virtual ~Item() {}
	MCAPI std::string const& getFullItemName() const;
};
