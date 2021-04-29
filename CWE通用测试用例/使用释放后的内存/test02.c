//check type:c/cpp
#include<malloc.h>
#include<string.h>
char *p1; //
void func_s_05_01_UAF_medium_03_bad()
{
	p1 = (char *)malloc(10);
	free(p1);              //not compliant
	strcpy(p1, "123456"); //not
}
//Ó¦¸ÃÎª
void func_s_05_01_UAF_medium_01_good()
{
	p1 = (char *)malloc(10);
	strcpy(p1, "123456");
	free(p1);
}
