//check type:cpp
//Language:CPP
#include<stdlib.h>
class s_06_03_test05_Data
{
	public:
		int number;
};

class s_06_03_medium_MLK_FMM_05_bad{
	s_06_03_test05_Data *data;
	public:
		s_06_03_medium_MLK_FMM_05_bad(unsigned int num);
		~s_06_03_medium_MLK_FMM_05_bad();
};
s_06_03_medium_MLK_FMM_05_bad::s_06_03_medium_MLK_FMM_05_bad(unsigned int num)
{
  if(num > 0)
  {
    data = new s_06_03_test05_Data[2];  //not compliant
  }
}
s_06_03_medium_MLK_FMM_05_bad::~s_06_03_medium_MLK_FMM_05_bad()
{
  delete data;
}
void func_s_06_03_medium_MLK_FMM_05_bad()
{
  s_06_03_medium_MLK_FMM_05_bad c1(2);
}
