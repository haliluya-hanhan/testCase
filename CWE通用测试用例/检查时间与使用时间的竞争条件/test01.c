//check type:c/cpp
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void  func_s_50_03_TOCTOU_FILE_ACCESS_basic_01_bad(char * file)
{
    FILE* f;
 if(!access(file, W_OK))     //not compliant【不推荐】不要使用函数access(),易引发条件竞争
 {
  f = fopen(file, "w+");
  /*...*/
  /* close f after operate(f)*/
 }
 else
 {
  fprintf(stderr, "Unable to open file %s.\n", file);
 }
 }
