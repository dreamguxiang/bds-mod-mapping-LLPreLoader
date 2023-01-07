#pragma once

#include "../Global.h"
#include <string>
#include <memory>
#include "Tag.h"
#include <map>

class CompoundTagVariant {

	char filler[0x30]; // IDA CompoundTagVariant::emplace
};

class CompoundTag : public Tag{
public:
	std::map<std::string, CompoundTagVariant> val;
	
	static std::unique_ptr<CompoundTag> create() {
		return std::unique_ptr<CompoundTag>((CompoundTag*)Tag::newTag(Tag::Type::Compound).release());
	}
	
	MCAPI CompoundTag();
	MCAPI CompoundTag(class CompoundTag&&);
	MCAPI void append(class CompoundTag const&);

	MCAPI class CompoundTag* putCompound(std::string, std::unique_ptr<class CompoundTag>);
	MCAPI short& putShort(std::string, short);

	MCAPI std::unique_ptr<class CompoundTag> clone() const;

	MCAPI unsigned __int64 size() const;

	virtual ~CompoundTag();
	virtual void write(class IDataOutput&) const;
	virtual void load(class IDataInput&);
	virtual std::string toString() const;
	virtual enum Tag::Type getId() const;
	virtual bool equals(class Tag const&) const;
	virtual void print(std::string const&, class PrintStream&) const;
	virtual std::unique_ptr<class Tag> copy() const;
	virtual unsigned __int64 hash() const;

};
