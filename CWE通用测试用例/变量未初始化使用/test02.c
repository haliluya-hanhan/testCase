//check type: C/CPP

#include <stdio.h>
struct s {
    int a;   
    int b;   
};

int func_s_15_01_UNINIT_basic_2_bad(void) 
{
    struct s x;
    x.b = 0;     
    return x.a; //not compliant
}

int func_s_15_01_UNINIT_basic_2_good(void) 
{
    struct s x;  
    x.b = 0;
	x.a = 1;
    return x.a;   
}
