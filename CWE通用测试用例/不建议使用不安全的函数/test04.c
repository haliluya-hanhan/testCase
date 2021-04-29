//check type:c/cpp 
#include <stdlib.h>
#include <stdio.h>
void func_s_04_04_BANNED_SPLITPATH_basic_01_bad( void )
{
   char path_buffer[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	_makepath( path_buffer, "c", "\\sample\\crt\\", "makepath", "c" );
	printf( "Path created with _makepath: %s\n\n", path_buffer );
	_splitpath( path_buffer, drive, dir, fname, ext );          //not compliant
	printf( "Path extracted with _splitpath:\n" );
}
