//check type:c/cpp
typedef int mytype;         
int func_GJB_R_01_01_03_basic_1_bad(void)
{
    typedef float mytype;    //not compliant
    mytype x = 1.0;
    return (0);
}
