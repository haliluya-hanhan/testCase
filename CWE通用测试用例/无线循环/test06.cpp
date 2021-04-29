//check type:cpp
//Language:CPP
using namespace std;
#include <iostream>
int func_s_23_04_basic_INFINITE_LOOP_LOGICAL_04_bad()
{
	unsigned int u;//
	for(u=10;u>=0;u--)//not compliant
	{
		cout<<u<<endl;
	}
	return 0;
}
