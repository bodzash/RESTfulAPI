#include "Guid.h"
#define UUID_SYSTEM_GENERATOR
#include "uuid.h"

Guid::Guid() noexcept
{
    static auto sGenFn = uuids::uuid_system_generator{};
    mID = uuids::to_string(sGenFn());
}