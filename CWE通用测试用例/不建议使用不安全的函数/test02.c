//check type:c/cpp 
#include <stdlib.h>
#include <stdio.h>
void func_s_04_02_BANNED_MAKEPATH_basic_01_bad( void )
{
  char path_buffer[_MAX_PATH];

  _makepath( path_buffer, "c", "\\sample\\crt\\", "makepath", "c" );    //not compliant
  printf( "Path created with _makepath: %s\n\n", path_buffer );
}
