#pragma once
#include "../Global.h"
#include "ReadOnlyBinaryStream.h"
#include "../HookAPI.h"

struct BinaryStream : ReadOnlyBinaryStream {
	std::string unk11;
	std::string* unk2;

	MCAPI BinaryStream();

	MCAPI void write(void const*, unsigned __int64);

	MCAPI void writeUnsignedShort(unsigned short);
	
	MCAPI void writeUnsignedVarInt(unsigned int);

    template <typename T>
    inline void writeType(T const&) = delete;
    template <>
    MCAPI void writeType(struct CommandOriginData const&);
    template <>
    MCAPI void writeType(std::vector<std::unique_ptr<class DataItem>> const&);
    template <>
    MCAPI void writeType(class NetworkItemStackDescriptor const&);
    template <>
    MCAPI void writeType(class MoveActorAbsoluteData const&);
    template <>
    MCAPI void writeType(class NetworkItemInstanceDescriptor const&);
    template <>
    MCAPI void writeType(struct ItemStackRequestSlotInfo const&);
    template <>
    MCAPI void writeType(class RecipeIngredient const&);
    
    void writeCompoundTag(class CompoundTag const& tag) {
        void (*rv)(class CompoundTag const&, class BinaryStream&);
        *((void**)&rv) = dlsym("?write@?$serialize@VCompoundTag@@@@SAXAEBVCompoundTag@@AEAVBinaryStream@@@Z");
        return (*rv)(tag, *this);
    }
};

static_assert(sizeof(BinaryStream) == 104);
