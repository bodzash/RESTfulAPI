#pragma once
#include <vector>
#include <string>
#include "Core/Guid.h"

class Breakfast
{
public:
    Breakfast(
        Guid ID,
        const std::string& Name,
        const std::string& Description,
        int StartDateTime, // DateTime
        int EndDateTime, // DateTime
        int LastModifiedDateTime, // DateTime
        const std::vector<std::string>& Savory,
        const std::vector<std::string>& Sweet
    ) noexcept
        : mID(ID), mName(Name), mDescription(Description), mStartDateTime(StartDateTime),
        mEndDateTime(EndDateTime), mLastModifiedDateTime(LastModifiedDateTime), mSavory(Savory), mSweet(Sweet)
    {}

    //Breakfast(const Breakfast& Other) noexcept {  }
    //Breakfast& operator=(const Breakfast& Other) noexcept { }

    const Guid& GetID() const { return mID; }
    const std::string& GetName() const { return mName; }
    const std::string& GetDescription() const { return mDescription; }
    int GetStartDateTime() const { return mStartDateTime; }
    int GetEndDateTime() const { return mEndDateTime; }
    int GetLastModifiedDateTime() const { return mLastModifiedDateTime; }
    const std::vector<std::string>& GetSavory() const { return mSavory; }
    const std::vector<std::string>& GetSweet() const { return mSweet; }

private:
    Guid mID;
    std::string mName;
    std::string mDescription;
    int mStartDateTime; // DateTime
    int mEndDateTime; // DateTime
    int mLastModifiedDateTime; // DateTime
    std::vector<std::string> mSavory;
    std::vector<std::string> mSweet;
};