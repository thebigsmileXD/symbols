#pragma once

#include "../../../../../unmapped/BoundingBox.h"
#include "../../../../util/Random.h"
#include "../StrongholdPiece.h"
#include <memory>
#include "../../../../block/unmapped/BlockSource.h"
#include "../StructurePiece.h"
#include <vector>


class SHLeftTurn : StrongholdPiece {

public:
    virtual ~SHLeftTurn();
    virtual void getType()const;
    virtual void addChildren(StructurePiece *, std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>> &, Random &);
    virtual void postProcess(BlockSource *, Random &, BoundingBox const&);

    void createPiece(std::vector<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>, std::allocator<std::unique_ptr<StructurePiece, std::default_delete<StructurePiece>>>> &, Random &, int, int, int, int, int);
    SHLeftTurn();
    SHLeftTurn(int, Random &, BoundingBox const&, int);
};
