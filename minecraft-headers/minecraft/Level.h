#pragma once
#include "../Global.h"

class Level {

public:
    MCVAPI class BlockPalette& getBlockPalette();
    MCVAPI class BlockPalette const& getBlockPalette() const;
    MCVAPI class BiomeRegistry& getBiomeRegistry();
    MCVAPI class BiomeRegistry const& getBiomeRegistry() const;
    
};
