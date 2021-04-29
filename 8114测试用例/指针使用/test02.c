//check type:c/cpp
#include <stdlib.h>
int fun(int para1, int para2);
int func_GJB_R_01_03_02_basic_1_bad(void)
{
    int a = 2, b = 1, c = 0;

    if (NULL == fun)                //not compliant
    {
        return -1;
    }
    else
    {
        int(*p)(int, int) = fun;    //not compliant
        c = p(a, b);
    }

    return 0;
}
int func_GJB_R_01_03_02_basic_1_good(void)
{
    int a = 2, b = 1, c = 0;

    if (NULL == &fun)               // ok-1
    {
        return -1;
    }
    else
    {
        int(*p)(int, int) = &fun;   // ok-2
        c = p(a, b);
    }

    return 0;
}
int fun(int para1, int para2)
{
    return (para1 - para2);
}
