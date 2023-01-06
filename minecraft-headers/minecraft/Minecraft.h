#pragma once

#include <memory>
#include "MinecraftCommands.h"

class Minecraft {
	
public:
	MCAPI class Level* getLevel() const;

	MCAPI class MinecraftCommands& getCommands();
};
