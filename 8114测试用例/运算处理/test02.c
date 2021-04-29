//check type:c/cpp
int fun(int p);
int func_GJB_R_01_06_05_basic_1_bad(void)
{
    int x = 1, y = 2, z = 3l;
    int r;
    y = y + (x++);  //not compliant
    z = z + (++y);  //not compliant
    z = fun(--z);   //not compliant
    r = fun(z--);   //not compliant
    return 0;
}
int func_GJB_R_01_06_05_basic_1_good(void)
{
    int x = 1, y = 2, z = 3l;
    int r;
    y = y + x;
    x++;            // ok-1
    y++;            // ok-2
    z = z + y;
    z--;            // ok-3
    z = fun(z);
    r = fun(z);
    z--;            // ok-4
    return 0;
}
int fun(int p)
{
    int ret;
    ret = 2*p;
    return ret;
}
