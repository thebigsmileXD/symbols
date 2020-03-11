#pragma once

#include "../storage/DBStorage.h"
#include <memory>
#include "./ChunkSource.h"
#include "./ChunkViewSource.h"
#include "../../Scheduler.h"
#include "../../block/unmapped/BlockSource.h"
#include "../../../unmapped/DBChunkStorageKey.h"
#include "../LevelChunkFinalDeleter.h"
#include "../../../unmapped/DBStorageWriteBatch.h"
#include "../LevelChunk.h"
#include <functional>


class DBChunkStorage : ChunkSource {

public:
    static long threadBatch;
    static std::string threadBuffer;

    virtual ~DBChunkStorage();
    virtual void shutdown();
    virtual bool isShutdownDone();
    virtual void postProcess(ChunkViewSource &);
    virtual void checkAndReplaceChunk(ChunkViewSource &, LevelChunk &);
    virtual void loadChunk(LevelChunk &, bool);
    virtual void saveLiveChunk(LevelChunk &);
    virtual void hintDiscardBatchBegin();
    virtual void hintDiscardBatchEnd();
    virtual void acquireDiscarded(std::unique_ptr<LevelChunk, LevelChunkFinalDeleter>);
    virtual void flushPendingWrites();

    DBChunkStorage(std::unique_ptr<ChunkSource, std::default_delete<ChunkSource>>, DBStorage &, Scheduler &);
    void _writeBatch();
    void _hasChunkUncached(DBChunkStorageKey const&);
    void _hasChunk(DBChunkStorageKey const&);
    void _loadChunkFromDB(LevelChunk &);
    void _applyChunkFixup(LevelChunk *, BlockSource &);
    void _upgradeFix(LevelChunk &, BlockSource &);
    void _loadAndBlendFromDB(LevelChunk &);
    void _serializeChunk(LevelChunk const&, DBStorageWriteBatch &);
    void _getBuffer();
    void freeCaches();
//  void registerUpgradeFixHandler(std::function<void (LevelChunk &, BlockSource &)>); //TODO: incomplete function definition
};
