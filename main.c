#include <stdlib.h>
#ifdef _WIN32
# include <crtdbg.h>
#endif




#include "i.h"















static int mainReturn(int r)
{
#if !defined(NDEBUG) && defined(_WIN32)
    system("pause");
#endif
    return r;
}


int main(int argc, char* argv[])
{
    mainReturn(0);
}


















































































