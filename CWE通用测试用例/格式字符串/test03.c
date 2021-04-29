//check type:c/cpp
#include<stdio.h>

int func_s_26_05_basic_FMT_STR_PRINT_IMPROP_LENGTH_01_bad()
{
	char str[256];
    scanf("%s", str);//not compliant
    return 0;
}

/*Ó¦¸ÄÎª£º*/
int func_s_26_05_basic_FMT_STR_PRINT_IMPROP_LENGTH_01_good()
{
	char str[256];
    scanf("%256s", str);
    return 0;
}

