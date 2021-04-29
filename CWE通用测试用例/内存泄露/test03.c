//check type:c/cpp
#include <stdlib.h>
#include <stdio.h>
#include "libavutil/mem.h"
int func_s_06_01_MLK_basic_36_bad(size_t size)
{
	char* p = (char*)av_malloc(size);   //not compliant
	if (!p) {
		printf("malloc fail\n");
		exit(-1);
	}
	return 0;
}
int func_s_06_01_MLK_basic_36_good(size_t size)
{
	char* p = (char*)av_malloc(size);
	if (!p) {
		printf("malloc fail\n");
		exit(-1);
	}
	av_free(p);
	return 0;
}