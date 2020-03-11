#pragma once

#include "../../util/Random.h"
#include "../../actor/Actor.h"
#include "../../util/BlockPos.h"
#include "../../block/unmapped/BlockSource.h"
#include "./TreeFeature.h"


class SpruceFeature : TreeFeature {

public:
    virtual ~SpruceFeature();
    virtual void place(BlockSource &, BlockPos const&, Random &)const;

    SpruceFeature(Actor *);
};
