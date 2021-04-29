//check type:c/cpp
#include<stdio.h>

int func_s_26_04_basic_FMT_STR_FORMAT_MISMATCH_01_bad()
{
	double n; //
    scanf("%d", &n);//not compliant
    return 0;
}

//Ó¦¸ÄÎª£º
int func_s_26_04_basic_FMT_STR_FORMAT_MISMATCH_01_good()
{
	double n;
    scanf("%f", &n);
    return 0;
}
