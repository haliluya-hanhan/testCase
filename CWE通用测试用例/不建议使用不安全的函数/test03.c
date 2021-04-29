//check type:c/cpp 
#include <stdlib.h>
#include <stdio.h>
void func_s_04_03_BANNED_OEM_basic_01_bad( void )
{
    char buff[1024]£»
    char buff2[1024]="hello world!";
	CharToOem(buff2, buff);   //not compliant
}
