//check type:c/cpp
#include <windows.h>
int func_s_30_05_basic_NPD_06_bad()
{
	char *b = NULL;;  
	*b = ' ';  //not compliant
	*b = 'a';  //not
	*b = 'b';  //not
	return 0;
}
int func_s_30_05_basic_NPD_06_good()
{
	char *b = NULL;;
	if(b != NULL)
    {
        *b = ' ';  //
        *b = 'a';  //
        *b = 'b';  //
    }
	return 0;
}
