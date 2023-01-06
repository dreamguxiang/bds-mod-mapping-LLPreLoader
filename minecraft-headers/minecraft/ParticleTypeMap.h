#include <string>
#include <vector>

enum class ParticleType;
template <typename T, typename T2>

class BidirectionalUnorderedMap {
public:
    std::unordered_map<T, T2> mMap1;
    std::unordered_map<T2, T> mMap2;
};


class ParticleTypeMap{
public:
	MCAPI static std::string const& getParticleName(enum class ParticleType);
    static std::unordered_map<std::string, ParticleType> getParticleNameTypeList(void) {
        return map.mMap2;
    }

	MCAPI static enum class ParticleType getParticleTypeId(std::string const&);
private:
    MCAPI static class BidirectionalUnorderedMap<enum class ParticleType, std::string> const map;
};
