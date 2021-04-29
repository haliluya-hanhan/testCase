//check type:c/cpp 
#include<stdio.h>
int func_GJB_A_01_09_02_basic_01_bad()
{
    int i;
    int Gstate;
	for(i = 0;i < 10; i++)   //not compliant
    {
        if(1 == Gstate)
        {
            break;
        }
        if(Gstate > 0 )
            break;
    }
    return 0;
}
