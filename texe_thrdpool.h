#pragma once



typedef struct TEXE_ThrdPool TEXE_ThrdPool;

TEXE_ThrdPool* TEXE_thrdPoolNew(u32 threadCount);
void TEXE_thrdPoolFree(TEXE_ThrdPool* pool);
bool TEXE_thrdPoolAdd(TEXE_ThrdPool* pool, TEXE_TaskFn fn, void* ctx, int64_t* done);































































































