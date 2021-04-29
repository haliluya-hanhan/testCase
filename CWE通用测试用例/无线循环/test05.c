//check type:c/cpp
//中航614
#include<stdio.h>
int main()
{
	//selectWfDem();
	//unsigned int i = 10;
	size_t i = 10;
	
	while(i >= 0)         //not compliant
	{
		printf("%u\t", i);
		i--;               /* 当 i 为 0 时， i-- 操作导致下溢翻转，变成该整型所能表示的最大值而导致死循环 */ 
	}
	return 0;
}
