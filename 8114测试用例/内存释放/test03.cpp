//check type:cpp 
#include <iostream>
using namespace std;
int func_GJB_R_02_06_03_basic_01_bad( void )
{
  int *p = new int[3];
  if(p == NULL)
   {
      return -1;
   }
  else
   {
     *p=1;
      p++;
     *p=2;
     delete[] p;      //not compliant
     p = NULL;
   }
 return 0;
}

/*good example*/
int func_GJB_R_02_06_03_basic_01_good( void )
{
  int *p = new int[3];
  int *pbak = p;
  if(p == NULL)
   {
      return -1;
   }
  else
   {
     *p=1;
      p++;
     *p=2;
     delete[] pbak;      //ok
     p = NULL;
   }
 return 0;
}

int R_2_6_3()
{
    int i;
    i = fun_R_2_6_3();
    return 0;
}
