#pragma once

#include "./MeleeAttackGoal.h"
#include "../Actor.h"
#include "../Mob.h"
#include <string>


class DelayedAttackGoal : MeleeAttackGoal {

public:
    virtual ~DelayedAttackGoal();
    virtual bool canUse();
    virtual bool canContinueToUse();
    virtual void start();
    virtual void stop();
    virtual void tick();
    virtual void appendDebugInfo(std::string &)const;
    virtual void _attemptPathToTarget(Actor *);
    virtual void _attemptAttackTarget(Actor *);

//  DelayedAttackGoal(Mob &, float, bool, float, ActorCategory, int, float, bool, int, int, LevelSoundEvent); //TODO: incomplete function definition
    void _isAttackAnimationStillRunning()const;
    void _attemptMoveToTargetPosition(Actor *);
    void _manageAttackTime();
    void _attemptStartAttacking(Actor const*);
    void _isAttackObstructed(Actor const*, int)const;
};
