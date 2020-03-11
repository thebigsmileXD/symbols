#pragma once

#include "../../../unmapped/SurfaceBuilderRegistry.h"
#include "../../../unmapped/IWorldRegistriesProvider.h"
#include "../../../unmapped/BiomeComponentFactory.h"
#include "../../../unmapped/BiomeRegistry.h"


class VanillaBiomes {

public:
    static long SWAMP_WATER_COLOR;
    static long WATER_FOG_COLOR_SWAMP;
    static long HEIGHTS_RIVER;
    static long HEIGHTS_OCEAN;
    static long HEIGHTS_DEEP_OCEAN;
    static long HEIGHTS_LOWLANDS;
    static long HEIGHTS_TAIGA;
    static long HEIGHTS_MOUNTAINS;
    static long HEIGHTS_HIGHLANDS;
    static long HEIGHTS_EXTREME;
    static long HEIGHTS_BEACH;
    static long HEIGHTS_STONE_BEACH;
    static long HEIGHTS_MUSHROOM;
    static long HEIGHTS_SWAMPLAND;
    static long mPlayerValidSpawns;
    static long mPlains;
    static long mDesert;
    static long mExtremeHills;
    static long mForest;
    static long mTaiga;
    static long mSwampland;
    static long mRiver;
    static long mNether;
    static long mSky;
    static long mFrozenRiver;
    static long mIceFlats;
    static long mIceMountains;
    static long mMushroomIsland;
    static long mMushroomIslandShore;
    static long mBeaches;
    static long mDesertHills;
    static long mForestHills;
    static long mTaigaHills;
    static long mSmallerExtremeHills;
    static long mJungle;
    static long mJungleHills;
    static long mJungleEdge;
    static long mBambooJungle;
    static long mBambooJungleHills;
    static long mStoneBeach;
    static long mColdBeach;
    static long mBirchForest;
    static long mBirchForestHills;
    static long mRoofedForest;
    static long mTaigaCold;
    static long mTaigaColdHills;
    static long mRedwoodTaiga;
    static long mRedwoodTaigaHills;
    static long mExtremeHillsWithTrees;
    static long mSavanna;
    static long mSavannaRock;
    static long mMesa;
    static long mMesaRock;
    static long mMesaClearRock;
    static long mOcean;
    static long mOceanDeep;
    static long mOceanCold;
    static long mOceanColdDeep;
    static long mOceanFrozen;
    static long mOceanFrozenDeep;
    static long mOceanLukewarm;
    static long mOceanLukewarmDeep;
    static long mOceanWarm;
    static long mOceanWarmDeep;
    static long mPlainsMutated;
    static long mSwamplandMutated;
    static long mIceFlatsMutated;
    static long mTaigaColdMutated;
    static long mSavannaMutated;
    static long mSavannaRockMutated;
    static long mRoofedForestMutated;


    void initBiomes(BiomeRegistry &);
    void initBiomeComponents(BiomeComponentFactory &);
    void initSurfaceBuilders(SurfaceBuilderRegistry &);
    void initDefaultWorldGenComponents(IWorldRegistriesProvider &);
    void initClientOnlyComponents(BiomeRegistry &);
    void initVanillaBiomeTypeComponent(BiomeRegistry &);
    void shutdownBiomes();
    bool isValidSpawn(int);
};
