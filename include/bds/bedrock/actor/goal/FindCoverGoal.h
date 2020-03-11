#pragma once

#include "../../util/Vec3.h"
#include "./Goal.h"
#include "../Mob.h"
#include <string>


class FindCoverGoal : Goal {

public:
    virtual ~FindCoverGoal();
    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void start();
    virtual void stop();
    virtual void appendDebugInfo(std::string &)const;

    FindCoverGoal(Mob &, float, float);
    void getHidePos(Vec3 *)const;
    void getMob()const;
};
