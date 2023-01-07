#pragma once

#include "../Global.h"
#include "Block.h"
#include "BlockLegacy.h"
#include "Item.h"

class ItemDescriptor {
	private:
		void *impl;

	public:
		
		MCAPI ItemDescriptor();
		MCAPI ItemDescriptor(class Item const&, int);
		MCAPI ItemDescriptor(class BlockLegacy const&);
		MCAPI ItemDescriptor(class Block const&);
		MCAPI ItemDescriptor(class ItemDescriptor const&);
		MCAPI ItemDescriptor(class ItemDescriptor&&);
	public:
		virtual ~ItemDescriptor(void);
		MCAPI void operator=(class ItemDescriptor const&);
		MCAPI void operator=(class ItemDescriptor&&);
		MCAPI class Item const* getItem() const;
		MCAPI class Block const* getBlock() const;
		MCAPI class WeakPtr<class BlockLegacy> const& getLegacyBlock() const;
		MCAPI bool isDefinedAsItemName() const;
		MCAPI bool isNull() const;
		MCAPI bool isValid(bool) const;
		MCAPI short getId() const;
		MCAPI short getAuxValue() const;
		MCAPI int getIdAux() const;
		MCAPI std::string getRawNameId() const;
		MCAPI std::string getSerializedNameAndAux() const;
		MCAPI std::string getFullName() const;
		MCAPI unsigned __int64 getHash() const;
		MCAPI bool operator==(class ItemDescriptor const&) const;
		//__declspec(dllimport) bool operator!=(const ItemDescriptor &) const;
};