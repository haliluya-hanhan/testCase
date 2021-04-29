//check type:c/cpp
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT "cmd.exe"
#define COMMAND_ARG1 "/c"
#define COMMAND_ARG2 "dir"
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH "/bin/sh"
#define COMMAND_INT "sh"
#define COMMAND_ARG1 "ls"
#define COMMAND_ARG2 "-la"
#define COMMAND_ARG3 data
#endif

#ifdef _WIN32
#include <process.h>
#define EXECL _execl
#define EXECLP _execlp
#define POPEN _popen
#define PCLOSE _pclose
#define SYSTEM system
#define EXECV _execv
#define EXECVP _execvp
#else /* NOT _WIN32 */
#define EXECL execl
#define EXECLP execlp
#define POPEN popen
#define PCLOSE pclose
#define SYSTEM system
#define EXECV _execv
#define EXECVP _execvp
#endif

int main(int argc,char*argv[])
{
    char data[100];
    fgets(data+100, (int)0, stdin);

    EXECL(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);     // not compliant
    EXECLP(COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);              // not compliant

    FILE *pipe;
    /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
    pipe = POPEN(data, "wb");                                                                       // not compliant
    SYSTEM(data);                                                                         // not compliant
    char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL};

    EXECV(COMMAND_INT_PATH, (const char * const *)args);                                            // not compliant
    EXECVP(COMMAND_INT, (const char * const *)args);                                                // not compliant
    _spawnv(_P_WAIT, COMMAND_INT_PATH, (const char * const *)args);                                 // not compliant
    _spawnvp(_P_WAIT, COMMAND_INT, (const char * const *)args);                                     // not compliant
    _spawnl(_P_WAIT, COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);   // not compliant
    _spawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);            // not compliant
    EXECV(COMMAND_INT_PATH,argv);   // not compliant
    EXECVP(COMMAND_INT, argv);  // not compliant
    return 0;
}
