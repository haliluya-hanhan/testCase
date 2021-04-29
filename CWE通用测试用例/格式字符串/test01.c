//check type:c/cpp
#include<stdio.h>

int func_s_26_02_basic_FMT_STR_PARAMS_WRONGNUM_01_bad()
{
   int n;
   scanf("%d %d", &n);//not compliant
   return 0;
}

/*Ó¦¸ÄÎª£º*/
int func_s_26_02_basic_FMT_STR_PARAMS_WRONGNUM_01_good()
{
   int n,m;
   scanf("%d %d", &n,&m);
   return 0;
}
