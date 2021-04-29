//check type: C/CPP

#include <stdio.h>
int f_15_01_UNINIT_5_bad(int a,int *c)
{
	a = 1;
	return 1;
}
int func_s_15_01_UNINIT_basic_5_bad(int b)
{
	int a;
  	int c = 2;
    if((c = f_15_01_UNINIT_5_bad(c,&a)) != 0)
	{  
		b = a;   //not compliant
	}
	return 0;
}


int f_15_01_UNINIT_5_good(int a,int *c)
{
	*c = 1;   //fixed
	return 1;
}


int func_s_15_01_UNINIT_basic_5_good(int b)
{
	int a;  
  	int c = 2;
    if((c = f_15_01_UNINIT_5_good(c,&a)) != 0)
	{  
		b = a;   // ok
	}
	return 0;
}
