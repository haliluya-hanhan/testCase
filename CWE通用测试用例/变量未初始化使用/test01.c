//check type: C/CPP

#include <stdio.h>
#include <string.h>
#include <wchar.h>
 
void func_s_15_01_UNINIT_basic_1_bad(const char *mbs) 
{
	size_t len;
	mbstate_t *state;

	len = mbrlen(mbs, strlen(mbs), state);  //not compliant
}

void func_s_15_01_UNINIT_basic_1_good(const char *mbs) 
{
	size_t len;
	mbstate_t mb = mbstate_t();  
	mbstate_t *state = &mb;    //fixed

	len = mbrlen(mbs, strlen(mbs), state);  
}
