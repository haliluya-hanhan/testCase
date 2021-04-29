//check type:cpp 
#include <iostream>
using namespace std;
class R_2_5_2
{
public:
  R_2_5_2(void);
  ~R_2_5_2(void);
  explicit R_2_5_2(int);
  int ma;
};

R_2_5_2::R_2_5_2(void)
{
	ma=0;
}

R_2_5_2::R_2_5_2(int a)
{
	ma=a;
}

R_2_5_2::~R_2_5_2(void)
{}

int func_GJB_R_02_05_02_basic_01_bad(void)
{
	R_2_5_2 const a1=R_2_5_2(10);
    R_2_5_2 *a2=const_cast<R_2_5_2*>(&a1);   //not compliant
    a2->ma=11;
    R_2_5_2 &a3=const_cast<R_2_5_2&>(a1);  //not compliant
    a3.ma=12;
    a2 = const_cast<R_2_5_2* const>(&a1);  //ok
    a2->ma=12;
    return 0;

}
