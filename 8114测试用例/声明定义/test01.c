//check type:c/cpp
#define long 10         //not compliant
int func_GJB_R_01_01_01_basic_1_bad(void)
{
    int i = 0;
    i = long;
    return 0;
}

#define LONG_NUM 100    // ok-1
int func_GJB_R_01_01_01_basic_1_good(void)
{
    int i;
    i = LONG_NUM;
    return 0;
}
