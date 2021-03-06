#include <stdlib.h>
#ifdef _WIN32
# include <crtdbg.h>
#endif



#include <stdio.h>
#include <assert.h>

#include <atomic.h>
#include <sleep.h>

#include "axe.h"



#ifdef ARYLEN
# undef ARYLEN
#endif
#define ARYLEN(a) (sizeof(a) / sizeof((a)[0]))



void taskFn(int64_t* count)
{
    atomic_inc(count);
}

static void test(void)
{
    AXE_init(0);
    static int64_t count[1] = { 0 };
    static int64_t done[1024 - 1] = { 0 };
    for (u32 i = 0; i < ARYLEN(done); ++i)
    {
        bool ok = AXE_exe(taskFn, count, done + i);
        assert(ok);
    }
    while (atomic_get(count) < ARYLEN(done));
    AXE_deinit();
    assert(ARYLEN(done) == atomic_get(count));
    for (u32 i = 0; i < ARYLEN(done); ++i)
    {
        assert(done[i]);
    }
}





static int mainReturn(int r)
{
#if !defined(NDEBUG) && defined(_WIN32)
    system("pause");
#endif
    return r;
}


int main(int argc, char* argv[])
{
    test();
    mainReturn(0);
}



















































































