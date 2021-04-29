//check type:c/cpp
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc < 1)
        return -1;

    char *env_argv[30];
    char *env_value = argv[1];
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
