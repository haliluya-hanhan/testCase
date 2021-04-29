//check type:cpp 
#include <iostream>
using namespace std;
void func_GJB_R_02_06_01_basic_01_bad1( void )
{
 int *p =new int;  //not compliant
 *p =1;
 //....
}
void func_GJB_R_02_06_01_basic_01_bad2( void )
{
 int *p =new int[3];  //not compliant
 p[0] = 1;
 p[1] = 2;
 p[2] = 3;
 //....
}


/*good example*/
void func_GJB_R_02_06_01_basic_01_good1( void )
{
 int *p =new int;  //ok
 *p =1;
 delete p;
 p = NULL;
}
void func_GJB_R_02_06_01_basic_01_good2( void )
{
 int *p =new int[3];  //ok
 p[0] = 1;
 p[1] = 2;
 p[2] = 3;
 delete[] p;
 p = NULL;
}
