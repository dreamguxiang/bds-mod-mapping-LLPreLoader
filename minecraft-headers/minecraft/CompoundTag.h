#pragma once

#include "../Global.h"
#include <string>
#include <memory>
#include "Tag.h"

class CompoundTag : public Tag{
public:
	char filler[48];
	static std::unique_ptr<CompoundTag> create() {
		return std::unique_ptr<CompoundTag>((CompoundTag*)Tag::newTag(Tag::Type::Compound).release());
	}
	
	MCAPI CompoundTag();
	MCAPI CompoundTag(class CompoundTag&&);
	MCAPI void append(class CompoundTag const&);

	MCAPI class CompoundTag* putCompound(std::string, std::unique_ptr<class CompoundTag>);
	MCAPI short& putShort(std::string, short);

	MCAPI std::unique_ptr<class CompoundTag> clone() const;

	virtual ~CompoundTag(void);
};
