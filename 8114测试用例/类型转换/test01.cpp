//check type:cpp 
#include <iostream>

struct S
{
    int i;
    int j;
    int k;
};
class R_2_5_1
{
public:
    int i;
    int j;
    int k;
    R_2_5_1(void);
    virtual ~R_2_5_1(void);
};

R_2_5_1::R_2_5_1(void):i(0),j(0),k(0)
{

}
R_2_5_1::~R_2_5_1(void)
{

}
int func_GJB_R_02_05_01_basic_01_bad()
{
    S *s = new S;
    s->i = 0;
    s->j = 0;
    s->k = 0;
    R_2_5_1 *b = new R_2_5_1;
    R_2_5_1 *c1 = reinterpret_cast<R_2_5_1 *>(s);  //not compliant
    R_2_5_1 *cc1 = (R_2_5_1*)s;  //not compliant
    c1 = reinterpret_cast<R_2_5_1 *>(b);   //ok
    cc1 = b;             //ok
   return 0;
}
