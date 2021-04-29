//check type:c/cpp 
#include <stdio.h>
int func_GJB_A_01_09_01_basic_01_bad(void)
{
    for(;;)		//	not compliant
	{
	}
	while(1)	//	not compliant
	{
	}
	do
	{
	}
	while(2);	//	not compliant
	return 0;
}
