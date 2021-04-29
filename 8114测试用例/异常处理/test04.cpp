//check type:cpp 
#include<iostream>
using namespace std;

class Exp
{
public:
	Exp(void){}
};
int func_GJB_R_02_08_04_basic_01_bad(void)
{
    try
    {
        Exp exp;
        throw Exp();
    }
    catch(...)    //not compliant
    {
        cout<<"exception"<<endl;
    }
    catch(Exp &e)
    {
       cout<<"exception:Exp"<<endl;
    }
    return 0;
}
int func_GJB_R_02_08_04_basic_01_good(void)
{
    try
    {
        throw Exp();
    }

    catch(Exp &e)
    {
       cout<<"exception:Exp"<<endl;
    }
    catch(...)
    {
        cout<<"exception"<<endl;
    }
    return 0;
}
