//check type:c/cpp
#include <winsock2.h>
#include <string.h>
#pragma comment( lib, "ws2_32.lib"  )

void func_s_19_02_basic_NNTS_TAINTED_05_bad()
{
   char src[32];//
   char src1[32];
   char dst[48];
    int a;
    switch(a)
    {
      case 0:
        read(0, src, sizeof(src));//
        strcpy(dst, src);//not compliant
        break;
      case 1:
         read(0, src1, sizeof(src1));//
         strcpy(dst, src1);//not compliant
         break;
      default:
        break;
    }
}
