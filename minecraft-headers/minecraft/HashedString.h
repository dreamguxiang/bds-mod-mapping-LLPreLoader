#pragma once

#include <string>

class HashedString{
public:
	unsigned long long hash;
	std::string str;
	HashedString* wtf;

	MCAPI HashedString(std::string const&);
	MCAPI HashedString(char const*);
};
