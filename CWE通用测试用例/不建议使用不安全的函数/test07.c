//check type:c/cpp 
#include <stdlib.h>
#include <stdio.h>
void func_s_04_07_BANNED_NSPRINTF_basic_01_bad( void )
{
    char dest[10];
	int ret;
    _snprintf( dest, 10, "<<<%d>>>", 12321 );   //not compliant
    ret = _snprintf_s( dest, sizeof(dest), 5, "<<<%d>>>", 121 );
}
