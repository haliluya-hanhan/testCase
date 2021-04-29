//check type:c/cpp
int func_GJB_R_01_06_02_basic_1_bad(void)
{
    unsigned char data1 = 256;      //not compliant
    signed char data2 = -129;       //not compliant
    // ......
    return 0;
}
int func_GJB_R_01_06_02_basic_1_good(void)
{
    unsigned short data1 = 256;     // ok-1
    short data2 = -129;             // ok-2
    // ......
    return 0;
}
