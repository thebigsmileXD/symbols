#pragma once

#include "../../../../../unmapped/BoundingBox.h"
#include "../OceanMonumentPiece.h"
#include "../../../../util/Random.h"
#include "../../../../definition/RoomDefinition.h"
#include <memory>
#include "../../../../block/unmapped/BlockSource.h"


class OceanMonumentCoreRoom : OceanMonumentPiece {

public:
    virtual ~OceanMonumentCoreRoom();
    virtual void getType()const;
    virtual void postProcess(BlockSource *, Random &, BoundingBox const&);

    OceanMonumentCoreRoom();
    OceanMonumentCoreRoom(int &, std::shared_ptr<RoomDefinition> &);
};
