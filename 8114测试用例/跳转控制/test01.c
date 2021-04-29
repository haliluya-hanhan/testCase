//check type:c/cpp
int func_GJB_R_01_05_01_basic_1_main(void)
{
    int i = -2, j = -2;
    int k;
    // ......
L0:
    i = i + 1;
    if (i < 0)
    {
        // ......
        goto L0;        //not compliant
    }
    if (j < 0)
    {
        k = -10;
        j = 0;
        goto L0;        //not compliant
    }
    for (k = 0; k < 10; k++)
    {
K1:
        j = j + k;
    }
    return 0;
}
