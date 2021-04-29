//check type:cpp 
#include<iostream>
using namespace std;

class Exp_R_2_8_3
{
public:
	Exp_R_2_8_3(void) : id(0)
	{}
	int get_docid(void);
private:
    int id;
};
int Exp_R_2_8_3::get_docid()
{
    return id;
}
int func_GJB_R_02_08_03_basic_01_bad(void)
{
    try
    {
        Exp_R_2_8_3 exp;
        throw &exp;  //not compliant
    }
    catch(Exp_R_2_8_3 *e)    //not compliant
    {
        cout<<e->get_docid()<<endl;
    }

    return 0;
}
/*good_example*/
int func_GJB_R_02_08_03_basic_01_good()
{
    try
    {
        Exp_R_2_8_3 exp;
        throw exp;  //ok
    }
    catch(Exp_R_2_8_3 &e)    //ok
    {
        cout<<e.get_docid()<<endl;
    }

    return 0;
}
