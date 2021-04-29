//check type:c/cpp
#include <winsock2.h>
#include <string.h>
#pragma comment( lib, "ws2_32.lib"  )
void func_s_19_02_basic_NNTS_TAINTED_03_bad()
{
   char src[32];//
   char dst[48];

   read(0, src, sizeof(src));//
   strcpy(dst, src);//not compliant
}

//Ó¦¸ÄÎª£º
void func_s_19_02_basic_NNTS_TAINTED_03_good()
{
   char src[32];
   char dst[48];

   read(0, src, sizeof(src));
   src[31]='\0';
   strcpy(dst, src);
}
