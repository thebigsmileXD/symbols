#pragma once

#include "../../unmapped/RenderParams"
#include "damagesource/ActorDamageSource"
#include "unmapped/ActorDefinitionGroup"
#include "../../unmapped/VariantParameterList"
#include "../util/Vec3"
#include "unmapped/ActorDefinitionIdentifier"
#include "../item/ItemStack"


class Agent : Mob {

public:
    virtual void initializeComponents(Actor::InitializationMethod, VariantParameterList const&);
    virtual Agent::~Agent()
    virtual bool breaksFallingBlocks()const;
    virtual void teleportTo(Vec3 const&, bool, int, int);
    virtual void normalTick();
    virtual bool isInvisible()const;
    virtual bool canShowNameTag()const;
    virtual void getFormattedNameTag()const;
    virtual void getAlwaysShowNameTag()const;
    virtual void interactPreventDefault();
    virtual bool isPickable();
    virtual bool isTargetable()const;
    virtual void handleEntityEvent(ActorEvent, int);
    virtual void setCarriedItem(ItemStack const&);
    virtual bool canBePulledIntoVehicle()const;
    virtual bool isWorldBuilder();
    virtual bool isAdventure()const;
    virtual void kill();
    virtual void updateEntitySpecificMolangVariables(RenderParams &);
    virtual void _hurt(ActorDamageSource const&, int, bool, bool);
    virtual void knockback(Actor *, int, float, float, float, float, float);
    virtual void travel(float, float, float);
    virtual void aiStep();
    virtual void createAIGoals();
    virtual bool canExistWhenDisallowMob()const;
    virtual void initBodyControl();

    Agent(ActorDefinitionGroup *, ActorDefinitionIdentifier const&);
    void setIdling(bool);
    void getSelectedSlot()const;
    void setSelectedSlot(int);
    void getItemFromSlot(int);
    void _getContainerComponent();
    bool isValidSlotNum(int);
    void tryFireCreateEvent(Player &);
    void setMoveTarget(Vec3 const&);
    void setNameTagFromOwner(Player const&);
    void getSwingAnimationTick();
    void getSwingAnimationDuration();
    void getMoveSpeedScalar()const;
    void swingArm();
    void swingAnimationCompleted();
    void roundTeleportPos(Vec3 const&);
    void startCommandMode();
    void stopCommandMode();
    bool isHovering();
    bool isIdling();
    void getRenderData();
};