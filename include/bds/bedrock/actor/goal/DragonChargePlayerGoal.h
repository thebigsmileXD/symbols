#pragma once

#include "./Goal.h"
#include "../EnderDragon.h"
#include <string>


class DragonChargePlayerGoal : Goal {

public:
    static long CHARGE_RECOVERY_TIME;
    static long SITTING_CHARGE_VIEW_RANGE;

    virtual ~DragonChargePlayerGoal();
    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void start();
    virtual void stop();
    virtual void tick();
    virtual void appendDebugInfo(std::string &)const;

    DragonChargePlayerGoal(EnderDragon &);
};
