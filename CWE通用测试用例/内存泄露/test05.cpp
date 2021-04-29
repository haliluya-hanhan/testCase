//check type:cpp
//Language:CPP
#include<stdlib.h>

class s_06_03_medium_MLK_FMM_06_bad {
	public:
		void foo();
};

void s_06_03_medium_MLK_FMM_06_bad::foo()
{
	int *ptr;
	ptr = (int*)malloc(sizeof(int));//not compliant
	delete ptr;//not
}
void func_s_06_03_medium_MLK_FMM_06_bad()
{
    s_06_03_medium_MLK_FMM_06_bad s;
    s.foo();
}

//以下是正确的例子
class s_06_03_medium_MLK_FMM_06_good {
	public:
		void foo();
};

void s_06_03_medium_MLK_FMM_06_good::foo()
{
	int *ptr;
	ptr = (int*)malloc(sizeof(int));//
	free(ptr);//not
}
void func_s_06_03_medium_MLK_FMM_06_good()
{
    s_06_03_medium_MLK_FMM_06_good s;
    s.foo();
}
