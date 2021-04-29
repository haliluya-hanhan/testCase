//check type:c/cpp
//Coverity
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int func_s_50_03_TOCTOU_FILE_ACCESS_basic_02_bad(char*argv[], int argc) {
    struct stat     buf;
    char* filename = "crt_stat.c";
     if(stat(filename, &buf) != 0) {  //not compliant
         printf("stat error.");
         return 0;
     }
    open(filename, O_RDWR);
}
