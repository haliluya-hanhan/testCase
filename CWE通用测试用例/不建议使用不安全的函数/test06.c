//check type:c/cpp 
#include <stdlib.h>
#include <stdio.h>
void func_s_04_06_BANNED_NSCANF_basic_01_bad( void )
{
     char        str1[] = "15 12 14...";
    wchar_t     str2[] = L"15 12 14...";
    char        s1[3];
    wchar_t     s2[3];
    int         i;
    float       fp;

    i = snscanf( str1, 6,  "%s %f", s1, 3, &fp);  //not compliant
    printf_s("_snscanf_s converted %d fields: ", i);
}
