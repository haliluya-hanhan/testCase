//check type:c/cpp
int func_GJB_R_01_06_01_basic_1_bad(void)
{
    int idata = 2.5;        //not compliant
    idata = idata + 1;
    return 0;
}
int func_GJB_R_01_06_01_basic_1_good(void)
{
    int idata = 3;          // ok-1
    idata = idata + 1;
    return 0;
}
