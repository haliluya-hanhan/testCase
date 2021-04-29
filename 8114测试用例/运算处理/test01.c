//check type:c/cpp
#include <string.h>
#define A(x,y) strcpy((x),(y))  //not compliant

void fun(void)
{
    char *s="Hello World!";
    char d[100];
    strcpy(d,s);    //not compliant
}

int main(void)
{
    char d[100];
    char *s="Hello World!";
    strcpy(d,s);    //not compliant
    for(int i=0; i<2; i++)
    {
        strcpy(d,s);  //not compliant
    }
    fun();
    A(d,s);
    return 0;
}
