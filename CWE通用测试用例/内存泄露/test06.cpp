// check type:CPP
#include <iostream>

using namespace std;

class A
{
public:
    A(){x=new int;}
    ~A(){delete x;}
private:
    int *x;
};

int func_s_06_04_DELETE_VOID_basic_01_bad()
{
    void *ptr;
    ptr = new A();
    delete ptr;     // not compliant
    return 0;
}

// fix_case
class A_fix{
public:
    A_fix(){}
private:
    int x;
};

int func_s_06_04_DELETE_VOID_basic_01_good()
{
    void *ptr;
    ptr = new A_fix();
    delete ptr;     // compliant
    return 0;
}
