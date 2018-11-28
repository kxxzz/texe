#include <stdlib.h>
#ifdef _WIN32
# include <crtdbg.h>
#endif



#include <stdio.h>
#include <assert.h>

#include <atomic.h>
#include <sleep.h>

#include "i.h"




static int64_t s_count = 0;


void taskFn(void* ctx)
{
    atomic_inc(&s_count);
    if (4096 == s_count)
    {
        printf("done\n");
    }
}

static void test(void)
{
    TE_init();
    sleep_ms(1);
    static int64_t done[4096] = { 0 };
    for (u32 i = 0; i < ARYLEN(done); ++i)
    {
        TE_exe(taskFn, NULL, done + i);
    }
    while (atomic_get(&s_count) < ARYLEN(done));
    sleep_ms(100);
    TE_deinit();
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



















































































