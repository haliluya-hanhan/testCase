//check type:c/cpp 
struct Sp
{
    unsigned int color;
    struct sc
    {
        unsigned int x;
        unsigned int y;
    }cs;
};
int func_GJB_R_01_11_03_basic_01_bad()
{
    struct Sp sp = {1, 2, 3};   //not compliant
    struct Sp sp1 = {1, {2, 3}};  //ok
    return 0;
}
