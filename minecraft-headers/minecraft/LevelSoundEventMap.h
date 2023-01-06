#include <string>

enum class LevelSoundEvent;
class LevelSoundEventMap{
public:
    MCAPI static enum class LevelSoundEvent getId(std::string const&);
    MCAPI static std::string const& getName(enum class LevelSoundEvent);
};
