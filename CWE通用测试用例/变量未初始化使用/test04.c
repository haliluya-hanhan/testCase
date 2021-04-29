//check type: C/CPP

#include <stdio.h>
#include <stdlib.h>

int add(int a,int b)
{
	return a+b;
}
int func_s_15_01_UNINIT_basic_4_bad(void)
{
	int an,bn;
	int ctl=2;
	int i=3;
	int next=4;
	switch(ctl)
	{
	case -1: an=0; bn=0; break;
	case 0: an=i; bn=-i; break;
	case 1: an=i+next; bn=i-next; break;
	default: an=-1; an=-1; break;  
	}
	ctl=add(an,bn);    //not compliant
	return 0;
}

int func_s_15_01_UNINIT_basic_4_good(void)
{
	int an,bn;  
	int ctl=2;
	int i=3;
	int next=4;
	switch(ctl)
	{
	case -1: an=0; bn=0; break;
	case 0: an=i; bn=-i; break;
	case 1: an=i+next; bn=i-next; break;
	default: an=-1; bn=-1; break;  
	}
	ctl=add(an,bn);   //bn
	return 0;
}

