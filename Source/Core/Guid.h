#pragma once
#include <string>

class Guid
{
public:
    Guid() noexcept;
    Guid(const std::string& ID) noexcept : mID(ID) {}
    const std::string& GetString() const { return mID; }

private:
    std::string mID;

    operator std::string() { return mID; }
};