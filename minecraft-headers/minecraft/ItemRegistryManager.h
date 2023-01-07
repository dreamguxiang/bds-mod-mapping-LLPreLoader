#pragma once
#include "../Global.h"

class ItemRegistryManager {
public:
    MCAPI static class ItemRegistryRef getItemRegistry();
    MCAPI static void resetItemRegistry();
    MCAPI static void setItemRegistry(class ItemRegistryRef);
};