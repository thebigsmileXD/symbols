#pragma once

#include "../bedrock/util/Vec3.h"
#include "./FlockingComponent.h"
#include "../bedrock/actor/Actor.h"
#include "../bedrock/actor/Mob.h"
#include "../bedrock/actor/unmapped/ActorUniqueID.h"


class FlockingComponent {

public:

    void getIsEnabled()const;
    void getInWater()const;
    void getIsLeader()const;
    ~FlockingComponent();
    FlockingComponent(FlockingComponent &&);
    void setGoalHeading(Vec3 const&);
    void setHasGoalTarget(bool);
    void setUsingDirection(bool);
    void breakFlock(Actor const&);
    void clearNeighborhood();
    void updateNeighborhoodData(Actor const&);
    void validateVariantEntityTypes(Actor const&, Actor const&)const;
    bool containsMember(ActorUniqueID);
    void manageNeighborhood(Actor &);
    void mergeNeighborhoods(Actor &);
    void calculateFlockVector(Actor const&);
    void calculateGoalHeading(Mob &);
    bool canJoinFlock(Actor &)const;
    void joinFlock(Actor &);
    void addFlockMember(ActorUniqueID);
    void getNeighborhood();
    void setFlockLimit(int);
    void setIsLeader(bool);
    void getSeparationWeight()const;
    void getCohesionWeight()const;
    void setCurrentHeading(Vec3 const&);
    void setInFlock(bool);
    void toggleFlock(bool);
    void setGroupVelocity(Vec3 const&);
    void getInFlock()const;
    void getFlockLimit()const;
    void getMinHeight()const;
    void getMaxHeight()const;
    FlockingComponent();
    void getGoalHeading()const;
    bool hasGoalTarget()const;
    void getUsingDirection()const;
    bool needsDoubleSpeed();
    void getCurrentHeading()const;
};
