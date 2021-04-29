//check type:c/cpp
/*   vs编译不通过，需在Linux环境�*/
#include <stdio.h>
#include <unistd.h>
#define PATH_MAX 1024
int func_s_19_02_basic_NNTS_TAINTED_04_bad()
{
	char buf[PATH_MAX];
	char filename[PATH_MAX];
	char* path;
    readlink(path, buf, PATH_MAX);
	strcpy(filename, buf); //not compliant
}


int func_s_19_02_basic_NNTS_TAINTED_04_good()
{
	char buf[PATH_MAX];
	char filename[PATH_MAX];
	char* path;
    readlink(path, buf, PATH_MAX);
    buf[PATH_MAX-1] = '\0';
	strcpy(filename, buf); //
}
