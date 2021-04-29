//check type:cpp 
#include <iostream>
using namespace std;
void func_GJB_R_02_06_02_basic_01_bad( void )
{
 int *p =new int[3];  //not compliant
 p[0] = 1;
 p[1] = 2;
 p[2] = 3;
 delete p;
 p = NULL;
}


/*good example*/
void func_GJB_R_02_06_02_basic_01_good( void )
{
 int *p =new int[3];
 p[0] = 1;
 p[1] = 2;
 p[2] = 3;
 delete[] p;       //ok
 p = NULL;
}
