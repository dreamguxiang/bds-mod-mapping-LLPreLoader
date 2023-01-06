#pragma once
#include <memory>
class Tag {
  public:
    virtual ~Tag(void);
    enum class Type : uint8_t {
        End,
        Byte,
        Short,
        Int,
        Int64,
        Float,
        Double,
        ByteArray,
        String,
        List,
        Compound,
        IntArray,
    };
     MCAPI static std::unique_ptr<class Tag> newTag(enum class Tag::Type);
  protected:
    Tag(void);
};
