//check type:cpp
#include <stdio.h>
#include <stdlib.h>
int func_s_27_06_TAINTED_INDIRECT_INDEX_ACCESS_basic_01_bad(int argc, char ** argv)
{
    char *env_argv[30];
    char *env_value = getenv ("BC_ENV_ARGS");
    int env_argc = 1;
    env_argv[0] = "BC_ENV_ARGS";
    while (*env_value != 0)
	{
	  if (*env_value != ' ')
	  {
	      env_argv[env_argc++] = env_value;   // not compliant
	  }
	 else
	    env_value++;
	}
    return 0;
}



int func_s_27_06_TAINTED_INDIRECT_INDEX_ACCESS_basic_01_good()
{
    char *env_argv[30];
    char *env_value = getenv ("BC_ENV_ARGS");
    int env_argc = 1;
    env_argv[0] = "BC_ENV_ARGS";
    while (*env_value != 0)
	{
	  if (*env_value != ' ')
	  {
         if(env_argc<30)return 0;
	      env_argv[env_argc++] = env_value;
	  }
	 else
	    env_value++;
	}
    return 0;
}
