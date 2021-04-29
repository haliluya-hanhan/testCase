//check type: C/CPP

#include <stdio.h>
int a;
int func_s_15_01_UNINIT_basic_3_bad(void)
{
    static int c;
    int d;
    int b;
    b=a;
    b=c;
    b=d;   //not compliant
    return 1;
}

int func_s_15_01_UNINIT_basic_3_good(void)
{
    static int c;
    int d;   	
    int b;
	d=2;
    b=a;
    b=c;
    b=d;   
    return 1;
}
