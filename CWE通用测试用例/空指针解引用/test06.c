//check type:c/cpp
#include<stdio.h>
void xstrcpy(char *dst, char *src){
	if(!src) return;
	dst[0] = src[0];				//not compliant
}

int func_s_30_05_basic_NPD_03_bad()
{
	int flag;
	char *arg;
	xstrcpy(NULL,"Hello");			
	return 0;
}

/*Ó¦¸ÄÎª*/
void goog_xstrcpy(char *dst, char *src) {
    if (!src) return;
    if (!dst) return;
    dst[0] = src[0];
}
int func_s_30_05_basic_NPD_03_good()
{
	int flag;
	char *arg;
	goog_xstrcpy(NULL,"Hello");
	return 0;
}
