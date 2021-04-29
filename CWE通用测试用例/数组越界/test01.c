//check type:c/cpp
#include <winsock2.h>
#include <string.h>
#include <stdio.h>
#pragma comment( lib, "ws2_32.lib"  )
int func_s_19_02_basic_NNTS_TAINTED_07_bad(void)
{
    char str[17];
    char *ptr,c='r';
    read(0, str, sizeof(str));
    ptr=strchr(str,c);   //not compliant
    if(ptr)
        printf("The character %cis at position:%s\n",c,ptr);
    else
        printf("The character was not found\n");
    return 0;
}
