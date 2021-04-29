//check type:c/cpp
#define JUDGE   if      //not compliant
#define int64   long    //not compliant
int main_bad(void)
{
    int64 i = 0;
    JUDGE(0 == i)
    {
        i = 1;
    }
    return 0;
}

#define JUDGE_ZERO(i)   if (0 == (i))   // ok-1
typedef long int64;                     // ok-2
int main_good(void)
{
    int64 i = 0;
    JUDGE_ZERO(i)
    {
        i = 1;
    }
    return 0;
}
