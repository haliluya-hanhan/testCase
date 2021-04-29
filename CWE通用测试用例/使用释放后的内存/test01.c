//check type:c/cpp
#include <malloc.h>
#include <string.h>
static char *LOC=(char*)0x0804c98c;
static char shellcode[]="\xeb\x0cjump12chars_""\x90";
void func_s_05_01_UAF_medium_01_bad()
{
  int size=sizeof(shellcode);
  char *shellcode_location;
  char *first;
  shellcode_location=(char*)malloc(size);
  strcpy(shellcode_location,shellcode);
  first=(char*)malloc(256);
  free(first);       		//not compliant
 *((char**)(first+0))=LOC-12;            //
 *((char**)(first+4))=shellcode_location;  //
  }
void func_s_05_01_UAF_medium_01_good()
{
  int size=sizeof(shellcode);
  char *shellcode_location;
  char *first;
  shellcode_location=(char*)malloc(size);
  strcpy(shellcode_location,shellcode);
  first=(char*)malloc(256);
 *((char**)(first+0))=LOC-12;            //
 *((char**)(first+4))=shellcode_location;  //
  free(first);       		//
  }
