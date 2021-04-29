//check type:c/cpp 
#include<stdio.h>
int func_GJB_A_01_09_03_basic_01_bad()
{
    int i;
    int Gstate;
	for(i = 0;i < 10; i++)   //not compliant
    {
        if(1 == Gstate)
        {
            continue;
        }
        if(Gstate > 0 )
            continue;
    }
    return 0;
}
