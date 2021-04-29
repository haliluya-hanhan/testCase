//check type:cpp 
#include<iostream>
using namespace std;

class Document_R_2_8_2
{
public:
	Document_R_2_8_2(void){}
};
class Document_R_2_8_2_01
{
public:
	Document_R_2_8_2_01(void){}
};

int func_GJB_R_02_08_02_basic_01_bad(void)
{

    int i = 0;
    try
    {
        if(i > 0)
        {
            throw Document_R_2_8_2();   //ok
        }
       else
        {
            throw Document_R_2_8_2_01();   //not compliant
        }
    }
    catch(Document_R_2_8_2 &)
    {
        cout<<"exception:A1"<<endl;
    }

    return 0;
}
int func_GJB_R_02_08_02_basic_01_good(void)
{

    int i = 0;
    try
    {
        if(i > 0)
        {
            throw Document_R_2_8_2();   //ok
        }
       else
        {
            throw Document_R_2_8_2_01();   //ok
        }
    }
    catch(Document_R_2_8_2 &)
    {
        cout<<"exception:A1"<<endl;
    }
    catch(Document_R_2_8_2_01 &)
    {
        cout<<"exception:A2"<<endl;
    }
    return 0;
}
