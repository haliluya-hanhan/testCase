//check type:c/cpp 
int func_GJB_R_01_11_01_basic_01_bad()
{
    int i;    //not compliant
    float x, y, z;  //not compliant
    x = z;
    if(0 == i)
    {
        y = z;
    }
    return 0;
}
/*good example*/
int func_GJB_R_01_11_01_basic_01_good()
{
    int i = 0;
    float x, y, z = 0.0;
    x = z;
    if(0 == i)
    {
        y = z;
    }
    return 0;
}
