//check type:c/cpp
#include  <math.h>
#include  <stdio.h>
int func_s_37_04_basic_RETVOID_01_bad ()  //not compliant
{
    int a=1;
	if(a>0)
		return;
	else
		return 1;
}
int func_s_37_04_basic_RETVOID_01_good ()  //
{
    int a=1;
	if(a>0)
		return 0;
	else
		return 1;
}
