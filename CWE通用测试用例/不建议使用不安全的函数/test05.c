//check type:c/cpp 
#include <stdlib.h>
#include <stdio.h>
void func_s_04_05_BANNED_ALLOCA_basic_01_bad( void )
{
   int *p = (int *)alloca(sizeof(int)*10);      //not compliant
	return 0;
}
