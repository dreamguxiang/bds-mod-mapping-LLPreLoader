#pragma once

#include <string>
#include <memory>
#include <vector>
#include "HookAPI.h"
#include "CompoundTag.h"

struct ReadOnlyBinaryStream {
	size_t      mReadPointer{};
	bool        mHasOverflowed;
	std::string mOwnedBuffer, * mBuffer;

	virtual ~ReadOnlyBinaryStream();

    template <typename T>
    inline void readType(T&) = delete;
    template <>
    MCAPI void readType(struct CommandOriginData&);
    template <>
    MCAPI void readType(class Experiments&);
    template <>
    MCAPI void readType(struct ItemStackRequestSlotInfo&);
    template <>
    MCAPI void readType(class MoveActorAbsoluteData&);
    template <>
    MCAPI void readType(class NetworkItemStackDescriptor&);
    template <>
    MCAPI void readType(class StructureSettings&);
    template <>
    MCAPI void readType(std::vector<std::unique_ptr<class DataItem>>&);
    std::unique_ptr<class CompoundTag> getCompoundTag() {
        auto tag = CompoundTag::create();
        class CompoundTag& (*rv)(class CompoundTag&, class ReadOnlyBinaryStream&);
        *((void**)&rv) = dlsym("?read@?$serialize@VCompoundTag@@@@SA?AVCompoundTag@@AEAVReadOnlyBinaryStream@@@Z");
        (*rv)(*tag, *this);
        return std::move(tag);
    }
	ReadOnlyBinaryStream(std::string const& buffer, bool copy);
	ReadOnlyBinaryStream(std::string&& buffer);
};

static_assert(offsetof(ReadOnlyBinaryStream, mBuffer) == 56);
static_assert(sizeof(ReadOnlyBinaryStream) == 64);
