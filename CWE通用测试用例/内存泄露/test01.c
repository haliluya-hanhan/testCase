//check type:c/cpp
#include<malloc.h>
void* func_s_06_01_MLK_basic_05()
{
    return malloc(10);	//not
}
void func_s_06_01_MLK_basic_05_bad()
{
    func_s_06_01_MLK_basic_05();//not compliant
}

//以下是正确得例子
void func_s_06_01_MLK_basic_05_good()
{
    void* ptr = func_s_06_01_MLK_basic_05();
    free(ptr);
}
