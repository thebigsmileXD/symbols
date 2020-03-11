#pragma once

#include "./Enchant.h"
#include <string>


class FrostWalkerEnchant : Enchant {

public:
    virtual ~FrostWalkerEnchant();
    virtual void getMinCost(int)const;
    virtual void getMaxCost(int)const;
    virtual void getMaxLevel()const;
    virtual bool isTreasureOnly()const;

//  FrostWalkerEnchant(Enchant::Type, Enchant::Frequency, std::string const&, std::string const&, int, int); //TODO: incomplete function definition
};
