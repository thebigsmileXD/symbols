#pragma once

#include <string>
#include "../../unmapped/Dimension.h"
#include "../../unmapped/SeatDescription.h"
#include "../item/ItemStack.h"
#include "../../unmapped/UIProfanityContext.h"
#include "damagesource/ActorDamageSource.h"
#include "../util/Vec3.h"
#include "effect/MobEffect.h"
#include <functional>
#include "../util/Random.h"
#include "unmapped/ActorDefinitionGroup.h"
#include "../description/property/CollisionBoxDescription.h"
#include "unmapped/ActorDefinitionIdentifier.h"
#include "../util/Vec2.h"
#include "./Actor.h"
#include "./ItemActor.h"
#include "./Mob.h"
#include "../../unmapped/HashedString.h"
#include "../description/property/EquipmentTableDescription.h"
#include "../../unmapped/MobEffectInstance.h"
#include "../block/unmapped/BlockSource.h"
#include "../util/BlockPos.h"
#include "../../unmapped/EntityRegistryOwned.h"
#include "../../unmapped/DataLoadHelper.h"
#include "../nbt/CompoundTag.h"
#include "unmapped/ActorLink.h"
#include "../../unmapped/ActionEvent.h"
#include "../../unmapped/RenderParams.h"
#include "../../unmapped/Attribute.h"
#include "../../unmapped/HashString.h"
#include <memory>
#include "unmapped/ActorUniqueID.h"
#include "../network/packet/UpdateTradePacket.h"
#include "unmapped/ActorRuntimeID.h"
#include "../network/packet/ChangeDimensionPacket.h"
#include "../../unmapped/VariantParameterList.h"
#include "../level/Level.h"
#include <vector>
#include "../network/packet/UpdateEquipPacket.h"
#include "../util/AABB.h"
#include "unmapped/ActorInteraction.h"
#include "./Player.h"
#include "../../unmapped/Block.h"


class Actor {

public:
    static long TOTAL_AIR_SUPPLY;
    static long DAMAGE_NEARBY_MOBS_DURATION;
    static long DEFAULT_AMBIENT_SOUND_INTERVAL;
    static long DEFAULT_AMBIENT_SOUND_INTERVAL_RANGE;
    static std::string RIDING_TAG;

//  virtual void reloadHardcoded(Actor::InitializationMethod, VariantParameterList const&); //TODO: incomplete function definition
//  virtual void reloadHardcodedClient(Actor::InitializationMethod, VariantParameterList const&); //TODO: incomplete function definition
//  virtual void initializeComponents(Actor::InitializationMethod, VariantParameterList const&); //TODO: incomplete function definition
//  virtual void reloadComponents(Actor::InitializationMethod, VariantParameterList const&); //TODO: incomplete function definition
    virtual bool hasComponent(Util::HashString const&)const;
    virtual ~Actor();
    virtual void reset();
    virtual void getOnDeathExperience();
    virtual void getOwnerEntityType();
    virtual void remove();
    virtual void setPos(Vec3 const&);
    virtual void getPos()const;
    virtual void getPosOld()const;
    virtual void getPosExtrapolated(float)const;
//  virtual void getAttachPos(ActorLocation, float)const; //TODO: incomplete function definition
    virtual void getFiringPos()const;
    virtual void setRot(Vec2 const&);
    virtual void move(Vec3 const&);
    virtual void getInterpolatedRidingPosition(float)const;
    virtual void getInterpolatedBodyRot(float)const;
    virtual void getInterpolatedHeadRot(float)const;
    virtual void getInterpolatedBodyYaw(float)const;
    virtual void getYawSpeedInDegreesPerSecond()const;
    virtual void getInterpolatedWalkAnimSpeed(float)const;
    virtual void getInterpolatedRidingOffset(float)const;
    virtual void checkBlockCollisions(AABB const&);
    virtual void checkBlockCollisions();
    virtual bool breaksFallingBlocks()const;
    virtual void blockedByShield(ActorDamageSource const&, Actor &);
    virtual void moveRelative(float, float, float, float);
    virtual void teleportTo(Vec3 const&, bool, int, int);
    virtual void tryTeleportTo(Vec3 const&, bool, bool, int, int);
    virtual bool chorusFruitTeleport(Vec3 &);
    virtual void lerpTo(Vec3 const&, Vec2 const&, int);
    virtual void lerpMotion(Vec3 const&);
    virtual void getAddPacket();
    virtual void normalTick();
    virtual void baseTick();
    virtual void rideTick();
    virtual void positionRider(Actor &, float);
    virtual void getRidingHeight();
    virtual void startRiding(Actor &);
    virtual void addRider(Actor &);
    virtual void flagRiderToRemove(Actor &);
//  virtual void getExitTip(std::string const&, InputMode)const; //TODO: incomplete function definition
    virtual void intersects(Vec3 const&, Vec3 const&)const;
    virtual bool isFree(Vec3 const&, float);
    virtual bool isFree(Vec3 const&);
    virtual bool isInWall()const;
    virtual bool isInvisible()const;
    virtual bool canShowNameTag()const;
    virtual bool canExistInPeaceful()const;
    virtual void setNameTagVisible(bool);
    virtual std::string getNameTag()const;
    virtual void getNameTagAsHash()const;
    virtual std::string getFormattedNameTag()const;
    virtual void filterFormattedNameTag(UIProfanityContext const&);
    virtual void setNameTag(std::string const&);
    virtual void getAlwaysShowNameTag()const;
    virtual void setScoreTag(std::string const&);
    virtual std::string getScoreTag()const;
    virtual bool isInWater()const;
    virtual bool hasEnteredWater()const;
    virtual bool isImmersedInWater()const;
    virtual bool isInWaterOrRain()const;
    virtual bool isInLava()const;
//  virtual bool isUnderLiquid(MaterialType)const; //TODO: incomplete function definition
    virtual bool isOverWater()const;
    virtual void makeStuckInBlock(float);
    virtual void getCameraOffset()const;
    virtual void getShadowHeightOffs();
    virtual void getShadowRadius()const;
    virtual void getHeadLookVector(float);
    virtual bool canSeeInvisible()const;
    virtual bool canSee(Actor const&)const;
    virtual bool canSee(Vec3 const&)const;
    virtual bool isSkyLit(float);
    virtual void getBrightness(float)const;
    virtual void interactPreventDefault();
    virtual void playerTouch(Player &);
    virtual void onAboveBubbleColumn(bool);
    virtual void onInsideBubbleColumn(bool);
    virtual bool isImmobile()const;
    virtual bool isSilent();
    virtual bool isPickable();
    virtual bool isFishable()const;
    virtual bool isSleeping()const;
    virtual bool isShootable();
    virtual bool isSneaking()const;
    virtual void setSneaking(bool);
    virtual bool isBlocking()const;
    virtual bool isDamageBlocked(ActorDamageSource const&)const;
    virtual bool isAlive()const;
    virtual bool isOnFire()const;
    virtual bool isOnHotBlock()const;
    virtual bool isCreativeModeAllowed();
    virtual bool isSurfaceMob()const;
    virtual bool isTargetable()const;
    virtual bool canAttack(Actor *, bool)const;
    virtual void setTarget(Actor *);
    virtual void findAttackTarget();
    virtual bool isValidTarget(Actor *)const;
    virtual void attack(Actor &);
    virtual void performRangedAttack(Actor &, float);
    virtual void adjustDamageAmount(int &)const;
    virtual void getEquipmentCount()const;
    virtual void setOwner(ActorUniqueID);
    virtual void setSitting(bool);
    virtual void onTame();
    virtual void onFailedTame();
    virtual void getInventorySize()const;
    virtual void getEquipSlots()const;
    virtual void getChestSlots()const;
    virtual void setStanding(bool);
    virtual bool canPowerJump()const;
    virtual void setCanPowerJump(bool);
    virtual bool isJumping()const;
    virtual bool isEnchanted()const;
    virtual void rideJumped();
    virtual void rideLanded(Vec3 const&, Vec3 const&);
    virtual void shouldRender()const;
    virtual bool isInvulnerableTo(ActorDamageSource const&)const;
    virtual void actuallyHurt(int, ActorDamageSource const*, bool);
    virtual void animateHurt();
    virtual void doFireHurt(int);
    virtual void onLightningHit();
    virtual void onBounceStarted(BlockPos const&, Block const&);
    virtual void feed(int);
//  virtual void handleEntityEvent(ActorEvent, int); //TODO: incomplete function definition
    virtual void getPickRadius();
    virtual void spawnAtLocation(int, int);
    virtual void spawnAtLocation(int, int, float);
    virtual void spawnAtLocation(Block const&, int);
    virtual void spawnAtLocation(Block const&, int, float);
    virtual void spawnAtLocation(ItemStack const&, float);
    virtual void despawn();
    virtual void killed(Actor &);
    virtual void awardKillScore(Actor &, int);
//  virtual void setArmor(ArmorSlot, ItemStack const&); //TODO: incomplete function definition
//  virtual void getArmor(ArmorSlot)const; //TODO: incomplete function definition
//  virtual void getArmorMaterialTypeInSlot(ArmorSlot)const; //TODO: incomplete function definition
//  virtual void getArmorMaterialTextureTypeInSlot(ArmorSlot)const; //TODO: incomplete function definition
//  virtual void getArmorColorInSlot(ArmorSlot, int)const; //TODO: incomplete function definition
//  virtual void setEquippedSlot(ArmorSlot, int, int); //TODO: incomplete function definition
//  virtual void setEquippedSlot(ArmorSlot, ItemStack const&); //TODO: incomplete function definition
    virtual void getCarriedItem()const;
    virtual void setCarriedItem(ItemStack const&);
    virtual void setOffhandSlot(ItemStack const&);
    virtual void getEquippedTotem()const;
    virtual void consumeTotem();
    virtual void save(CompoundTag &);
    virtual void saveWithoutId(CompoundTag &);
    virtual void load(CompoundTag const&, DataLoadHelper &);
    virtual void loadLinks(CompoundTag const&, std::vector<ActorLink, std::allocator<ActorLink>> &, DataLoadHelper &);
    virtual void getEntityTypeId()const;
    virtual void queryEntityRenderer()const;
    virtual void getSourceUniqueID()const;
    virtual void setOnFire(int);
    virtual void getHandleWaterAABB()const;
    virtual void handleInsidePortal(BlockPos const&);
    virtual void getPortalCooldown()const;
    virtual void getPortalWaitTime()const;
    virtual void getDimensionId()const;
    virtual bool canChangeDimensions()const;
//  virtual void changeDimension(AutomaticID<Dimension, int>, bool); //TODO: incomplete function definition
    virtual void changeDimension(ChangeDimensionPacket const&);
    virtual void getControllingPlayer()const;
    virtual void checkFallDamage(float, bool);
    virtual void causeFallDamage(float);
    virtual void handleFallDistanceOnServer(float, bool);
//  virtual void playSynchronizedSound(LevelSoundEvent, Vec3 const&, Block const&, bool); //TODO: incomplete function definition
//  virtual void playSynchronizedSound(LevelSoundEvent, Vec3 const&, int, bool); //TODO: incomplete function definition
    virtual void onSynchedDataUpdate(int);
    virtual bool canAddRider(Actor &)const;
    virtual bool canBePulledIntoVehicle()const;
    virtual void inCaravan()const;
    virtual bool isLeashableType();
    virtual void tickLeash();
    virtual void sendMotionPacketIfNeeded();
    virtual bool canSynchronizeNewEntity()const;
    virtual void stopRiding(bool, bool, bool);
    virtual void startSwimming();
    virtual void stopSwimming();
    virtual void buildDebugInfo(std::string &)const;
    virtual void getCommandPermissionLevel()const;
    virtual void getMutableAttribute(Attribute const&);
    virtual void getAttribute(Attribute const&)const;
    virtual void getDeathTime()const;
    virtual void heal(int);
    virtual bool isInvertedHealAndHarm()const;
    virtual bool canBeAffected(int)const;
    virtual bool canBeAffected(MobEffectInstance const&)const;
    virtual bool canBeAffectedByArrow(MobEffectInstance const&)const;
    virtual void onEffectAdded(MobEffectInstance &);
    virtual void onEffectUpdated(MobEffectInstance const&);
    virtual void onEffectRemoved(MobEffectInstance &);
    virtual void getAnimationComponent();
    virtual void openContainerComponent(Player &);
    virtual void swing();
//  virtual void useItem(ItemStack &, ItemUseMethod, bool); //TODO: incomplete function definition
    virtual bool hasOutputSignal(unsigned char)const;
    virtual void getOutputSignal()const;
    virtual void getDebugText(std::vector<std::string, std::allocator<std::string>> &);
    virtual void getMapDecorationRotation()const;
    virtual void getRiderYRotation(Actor const&)const;
    virtual void getYHeadRot()const;
    virtual bool isWorldBuilder();
    virtual bool isCreative()const;
    virtual bool isAdventure()const;
    virtual void add(ItemStack &);
    virtual void drop(ItemStack const&, bool);
    virtual void getInteraction(Player &, ActorInteraction &, Vec3 const&);
    virtual bool canDestroyBlock(Block const&)const;
    virtual void setAuxValue(int);
    virtual void setSize(float, float);
    virtual void getLifeSpan()const;
    virtual void onOrphan();
    virtual void wobble();
    virtual bool wasHurt();
    virtual void startSpinAttack();
    virtual void stopSpinAttack();
    virtual void setDamageNearbyMobs(bool);
//  virtual void renderDebugServerState(Options const&); //TODO: incomplete function definition
    virtual void reloadLootTable();
    virtual void reloadLootTable(EquipmentTableDescription const*);
    virtual void getDeletionDelayTimeSeconds()const;
    virtual void kill();
    virtual void die(ActorDamageSource const&);
    virtual void shouldTick()const;
    virtual void updateEntitySpecificMolangVariables(RenderParams &);
    virtual bool canMakeStepSound()const;
    virtual void outOfWorld();
    virtual void _hurt(ActorDamageSource const&, int, bool, bool);
    virtual void markHurt();
    virtual void readAdditionalSaveData(CompoundTag const&, DataLoadHelper &);
    virtual void addAdditionalSaveData(CompoundTag &);
    virtual void _playStepSound(BlockPos const&, Block const&);
    virtual void _playFlySound(BlockPos const&, Block const&);
    virtual void _makeFlySound()const;
    virtual void checkInsideBlocks(float);
    virtual void pushOutOfBlocks(Vec3 const&);
    virtual void updateWaterState();
    virtual void doWaterSplashEffect();
    virtual void spawnTrailBubbles();
    virtual void updateInsideBlock();
    virtual void getLootTable();
    virtual void getDefaultLootTable();
    virtual void _removeRider(ActorUniqueID const&, bool, bool);
    virtual void _onSizeUpdated();
    virtual void _doAutoAttackOnTouch(Actor &);

    void getEntity();
    bool hasEntity()const;
    Actor(ActorDefinitionGroup *, ActorDefinitionIdentifier const&);
    void setBaseDefinition(ActorDefinitionIdentifier const&, bool, bool);
    Actor(Level &);
    void getStateVectorComponentNonConst();
    void initEntity(EntityRegistryOwned &);
    void removeEntity();
    void reload();
    bool isRegionValid()const;
    void updateDescription();
    void getLevel();
    void _setupServerAnimationComponent();
//  bool hasCategory(ActorCategory)const; //TODO: incomplete function definition
    void requireReload();
    void reloadIfRequired();
    void sendActorDefinitionEventTriggered(std::string const&);
//  bool hasType(ActorType)const; //TODO: incomplete function definition
    void executeEvent(std::string const&, VariantParameterList const&);
    void getInitializationMethod();
    void setLeashHolder(ActorUniqueID);
    void getLeashHolder()const;
    void getStateVectorComponent()const;
    void _getStateVectorComponentNonConst();
    void _defaultInitEquipmentDropChances();
    void setVariant(int);
    void setMarkVariant(int);
    void setSkinID(int);
//  void setColor(PaletteColor); //TODO: incomplete function definition
//  void setColor2(PaletteColor); //TODO: incomplete function definition
//  void setStatusFlag(ActorFlags, bool); //TODO: incomplete function definition
//  void getStatusFlag(ActorFlags)const; //TODO: incomplete function definition
    bool isBaby()const;
    void updateBBFromDescription();
    void setCanClimb(bool);
    void setCanFly(bool);
    void setWASDControlled(bool);
    void setStrengthMax(int);
    void setStrength(int);
    void getAttributes();
    bool hasTags()const;
    void addDefinitionGroup(std::string const&);
    void removeDefinitionGroup(std::string const&);
    bool hasDefinitionGroup(std::string const&)const;
    bool hasFamily(Util::HashString const&)const;
    bool hasTag(std::string const&)const;
    void addTag(std::string const&);
    void removeTag(std::string const&);
    std::string getTags()const;
    void deregisterTagsFromLevelCache();
    bool hasUniqueID()const;
    bool hasRuntimeID()const;
    void getRuntimeID()const;
    void getRideRuntimeID()const;
    void getRide()const;
    void getUniqueID()const;
    void setRuntimeID(ActorRuntimeID);
    void setUniqueID(ActorUniqueID);
    void migrateUniqueID(ActorUniqueID);
    void getEntityData();
    void setPersistent();
    bool isInClouds()const;
    bool isUnderWaterfall()const;
    bool canBeginOrContinueClimbingLadder(bool)const;
    void onLadder(bool)const;
    bool canClimb()const;
    bool isClimbing()const;
    void getVariant()const;
    void getMarkVariant()const;
    void getSkinID()const;
    void getTarget()const;
    void getLevel()const;
    void getTargetId();
    void initParams(VariantParameterList &);
    void calculateAttackDamage(Actor &);
    bool hasEffect(MobEffect const&)const;
    void getEffect(MobEffect const&)const;
    void setBlockTarget(BlockPos const&);
    void getBlockTarget()const;
    bool isStackable()const;
    bool isTame()const;
    bool isTrusting()const;
    void getOwner()const;
    void getOwnerId()const;
    void getPlayerOwner()const;
    bool isSitting()const;
    bool isLayingDown()const;
    void setLayingDown(bool);
    void getAABBShapeComponent()const;
    void getRegion()const;
    void getDimension()const;
    bool isPersistent()const;
    bool hasSubBBInLava()const;
    void _containsSneakCollisionShapes(AABB const&);
    void getCollidableMobNear();
    void testForCollidableMobs(BlockSource &, AABB const&, std::vector<AABB, std::allocator<AABB>> &);
    void moveBBs(Vec3 const&);
    void getTempted()const;
    void testForEntityStacking(BlockSource &, AABB const&, std::vector<AABB, std::allocator<AABB>> &);
    void _getAABBShapeComponentNonConst();
    void _getBlockOnPos();
    void setCollidableMobNear(bool);
    void _playMovementSound(bool);
    bool isInScaffolding()const;
//  void playSound(LevelSoundEvent, Vec3 const&, Block const&); //TODO: incomplete function definition
//  void playSound(LevelSoundEvent, Vec3 const&, int); //TODO: incomplete function definition
    void onOnewayCollision(BlockPos);
    void onOnewayCollision(AABB const&);
    void _updateOnewayCollisions(BlockSource &);
    void checkEntityOnewayCollision(BlockSource &, BlockPos const&);
    void getCollidableMob();
    void _updateOwnerChunk();
    bool isInWorld()const;
    void moveChunks();
    void _refreshAABB();
    void setPosPrev(Vec3 const&);
    void setPosDirectLegacy(Vec3 const&);
    void setAABBDim(Vec2 const&);
    void setPreviousPosRot(Vec3 const&, Vec2 const&);
    void getLocator(HashedString const&);
    void getActorToWorldTransform(float, bool, Vec3 const&)const;
    void getInterpolatedRotation(float)const;
    void getRadius()const;
    void getCenter(float)const;
    void getInterpolatedPosition(float)const;
    void getViewVector(float)const;
    void getViewVector2(float)const;
    void operator==(Actor &);
    void setEnforceRiderRotationLimit(bool);
    void getSpeedInMetersPerSecond()const;
    void getVerticalSpeedInMetersPerSecond()const;
    void enforceRiderRotationLimit()const;
    void _damageNearbyMobs();
    void getDamageNearbyMobs()const;
    void updateInBubbleColumnState();
    bool isFireImmune()const;
    void burn(int, bool);
    void tick(BlockSource &);
    bool isGlobal()const;
    void setRegion(BlockSource &);
    bool hasTickingArea()const;
    void refreshComponents();
    bool isControlledByLocalInstance()const;
    bool isSwimming()const;
    void _manageRiders(BlockSource &);
    void updateTickingData();
    bool isRiding()const;
    bool isRemoved()const;
    void getLinks()const;
    void _sendLinkPacket(ActorLink const&)const;
    void _getTallestCollisionShape(AABB const&, AABB const&, Vec3 const&);
    void updateBBFromDescription(CollisionBoxDescription const&);
    void removeAllRiders(bool, bool);
    void positionAllRiders();
    void getRideRoot()const;
    void getFirstRider()const;
    bool hasRider()const;
    bool hasFishingHook()const;
    void fetchFishingHook();
    void clearFishingHookID();
    void setFishingHookID(ActorUniqueID);
    void _tryPlaceAt(Vec3 const&);
    void _exitRide(Actor const&, float);
    void getRotation()const;
    void moveTo(Vec3 const&, Vec2 const&);
    void _sendDirtyActorData();
    bool isRider(ActorUniqueID const&)const;
    void _setAABB(AABB const&);
    void _setAABBDim(Vec2 const&);
    void _setHeightOffset(float);
    void _setPos(Vec3 const&);
    void _setPosPrev(Vec3 const&);
    void setScared(bool);
    bool isScared()const;
    void setSeatDescription(Vec3 const&, SeatDescription const&);
    void buildDebugGroupInfo(std::string &)const;
    void spawnDustParticles(int);
    bool hasTeleported()const;
    void _isValidBlockToTeleportOnto(Block const&, bool)const;
    void teleportRidersTo(Vec3 const&, int, int);
    void distanceTo(Actor const&)const;
    void distanceTo(Vec3 const&)const;
    void distanceToSqr(Vec3 const&)const;
    void distanceToSqr(Actor const&)const;
    void distanceSqrToBlockPosCenter(BlockPos const&)const;
    void hurt(ActorDamageSource const&, int, bool, bool);
    void spawnTamingParticles(bool);
    void _randomHeartPos();
    void _spawnPukeParticles();
    void _spawnTreasureHuntingParticles();
    bool isInLove()const;
    bool isBribed()const;
    bool canMate(Actor const&)const;
    bool isAngry()const;
    bool isSheared()const;
    bool isChested()const;
    bool isIgnited()const;
    bool hasSaddle()const;
    bool isDancing()const;
    void setDancing(bool);
    bool isCharged()const;
    void setCharged(bool);
    bool isPowered()const;
    void setPowered(bool);
    void setTempted(bool);
    void setTradeInterest(bool);
    void getTradeInterest()const;
    void setSaddle(bool);
    void setClimbing(bool);
    bool isWalker()const;
    void setWalker(bool);
    bool isSwimmer()const;
    void setSwimmer(bool);
    bool isDoorBreaker()const;
    void setDoorBreaker(bool);
    bool isDoorOpener()const;
    void setDoorOpener(bool);
    bool isBreakingObstruction()const;
    void setBreakingObstruction(bool);
    void getSwimAmount(float)const;
    void getCurrentSwimAmount()const;
    bool canCurrentlySwim()const;
    bool canFly()const;
    bool isMoving()const;
    void setMoving(bool);
    bool isResting()const;
    void setResting(bool);
    bool isStanding()const;
    bool isWASDControlled();
    bool isDelayedAttacking()const;
    void setDelayedAttacking(bool);
    void setEnchanted(bool);
    void getJumpDuration()const;
    void setJumpDuration(int);
    void getControllingSeat();
    void setControllingSeat(int);
    void getStrength()const;
    bool isOverScaffolding()const;
    void spawnDeathParticles();
    void spawnEatParticles(ItemStack const&, int);
    void spawnBalloonPopParticles();
    void getColor()const;
    void getRegionConst()const;
    void getDimensionConst()const;
    void resetRegion();
    void getAmbientSoundIntervalMin(float &)const;
    void getAmbientSoundIntervalRange(float &)const;
    void getAmbientSoundEvent()const;
    void pickUpItem(ItemActor &);
    void pickUpItem(ItemActor &, int);
    bool hasLevel()const;
    void getArmorContainer();
    void getArmorContainer()const;
    void getHandContainer();
    void getHandContainer()const;
    void getOffhandSlot()const;
    bool hasPriorityAmmunition()const;
    bool hasTotemEquipped()const;
    void _serializeComponents(CompoundTag &);
    void saveLinks()const;
    void saveEntityFlags(CompoundTag &);
    void getColor2()const;
    void getStrengthMax()const;
    bool isOrphan()const;
    void loadEntityFlags(CompoundTag const&, DataLoadHelper &);
    void _convertOldSave(CompoundTag const&);
    void getActorIdentifier()const;
    void setChanged();
    void getEntityData()const;
//  void _setActorTypeId(ActorType); //TODO: incomplete function definition
    void getSpatialNetworkData()const;
    void getSpatialNetworkData();
    bool isDebugging()const;
    void getRandomPointInAABB(Random &);
    bool isInsideBorderBlock(float)const;
    bool hasPlayerRider()const;
    bool isRider(Actor const&)const;
    void getRiderIndex(Actor &)const;
    void getFirstAvailableSeatPos(Actor &, Vec3 &)const;
    void getShakeTime()const;
    void setShakeTime(int);
    void pullInEntity(Actor &);
    bool isRiding(Actor *)const;
    bool isLeashed()const;
    void getRenderLeashHolder();
    void _initializeLeashRopeSystem();
    void dropLeash(bool, bool);
//  void forEachLeashedActor(std::function<void (Actor *)>); //TODO: incomplete function definition
    void getAirSupply()const;
    void getTotalAirSupply()const;
    bool isAutoSendEnabled()const;
    void sendMotionToServer();
    void setGlobal(bool);
    bool isAutonomous()const;
    void setAutonomous(bool);
    void getHealth()const;
    bool isInsidePortal();
    void enableAutoSendPosRot(bool);
    void getEntityTerrainInterlockData();
    void _tryPlantWitherRose();
    void getHurtColor()const;
    void _setDimension(Dimension &);
    void buildForward()const;
    void getPortalEntranceAxis()const;
//  void _setNetherPortalData(AutomaticID<Dimension, int>, AutomaticID<Dimension, int>, int); //TODO: incomplete function definition
    void _setLevelPtr(Level *);
    void getRandom()const;
    bool isClient()const;
//  bool hasAttributeBuff(AttributeBuffType)const; //TODO: incomplete function definition
    void getMaxHealth()const;
    void serializationSetHealth(int);
    void healEffects(int);
    void addEffect(MobEffectInstance const&);
    void removeEffect(int);
    void removeAllEffects();
    void removeEffectParticles();
    void removeEffectNoUpdate(int);
    void getActiveEffectCount()const;
    bool hasAnyVisibleEffects()const;
    bool hasAnyEffects()const;
    void getAllEffects()const;
    void setInvisible(bool);
    void updateInvisibilityStatus();
    void getEconomyTradeableComponent()const;
    void resetClientAnimations();
    bool hasPersistingTrade()const;
    void getPersistingTradeOffers();
    void getPersistingTradeRiches();
    void savePersistingTrade(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag>>, int);
    void removePersistingTrade();
    bool isTickingEntity()const;
    void getTickingArea();
    void transferTickingArea(Dimension &);
    bool canOpenContainer(Player &)const;
    void setLastHitBB(Vec3 const&, Vec3 const&);
    bool isWithinRestriction()const;
    bool isWithinRestriction(BlockPos const&)const;
    bool hasRestriction()const;
    void restrictTo(BlockPos const&, float);
    void getRestrictCenter()const;
    void getRestrictRadius()const;
    void clearRestriction();
    void dropTowards(ItemStack const&, Vec3);
    void lovePartnerId()const;
    void setInLove(Actor *);
    void calcCenterPos()const;
    bool hasEnoughFoodToBreed();
    void _countFood(int);
    bool hasExcessFood();
    bool wantsMoreFood();
    void doEnchantDamageEffects(Mob &, Mob &);
    void setChainedDamageEffects(bool);
    void getChainedDamageEffects()const;
    void getTradeOffers();
    void getSlotAllowedItems(int);
    void setEquipFromPacket(UpdateEquipPacket const&);
    void createUpdateEquipPacket(int);
    void setOffersFromPacket(UpdateTradePacket const&);
    void createUpdateTradePacket(int);
    void setCollidableMob(bool);
    void setExperimental(bool);
    bool isExperimental()const;
    bool wasLastHitByPlayer();
    void setTradingPlayer(Player *);
    void getTradingPlayer()const;
    bool isTrading()const;
    void pushBackActionEventToActionQueue(ActionEvent);
    void getNextActionEvent(ActionEvent &);
    void clearActionQueue();
    bool isActionQueueEmpty()const;
    void setLimitedLife(int);
    void onChunkDiscarded();
    void shouldOrphan(BlockSource &);
    void setStructuralIntegrity(int);
    void getStructuralIntegrity()const;
    void setHurtTime(int);
    void getHurtTime()const;
    void setHurtDir(int);
    void getHurtDir()const;
    bool isSafeToSleepNear()const;
//  void fetchNearbyActorsSorted(Vec3 const&, ActorType); //TODO: incomplete function definition
    void getMolangVariables();
    void updateMolangVariables(RenderParams &);
    void cacheComponentData();
    bool isInPrecipitation()const;
    bool isInRain()const;
    bool isInSnow()const;
    bool isInThunderstorm()const;
    void _getLevelPtr()const;
    void getEntity()const;
    bool isInitialized();
};
