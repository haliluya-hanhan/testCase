//check type:c/cpp
#include <stdlib.h>
unsigned int func_GJB_R_01_03_03_basic_1_bad(unsigned int *pa);
unsigned int func_GJB_R_01_03_03_basic_1_good(unsigned int **pa);
int main(void)
{
    unsigned int data1, data2=NULL;
    unsigned int result1, result2;
    result1 = func_GJB_R_01_03_03_basic_1_bad(&data1);
    result2 = func_GJB_R_01_03_03_basic_1_good(&data2);
    return 0;
}
unsigned int func_GJB_R_01_03_03_basic_1_bad(unsigned int *pa)
{
    static unsigned int i = 10;
    i = i + 1;
    pa = &i;        //not compliant
    return i;
}
unsigned int func_GJB_R_01_03_03_basic_1_good(unsigned int **pa)
{
    static unsigned int i = 10;
    i = i + 1;
    *pa = &i;       // ok-1
    return i;
}
