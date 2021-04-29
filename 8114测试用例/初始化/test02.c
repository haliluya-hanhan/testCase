//check type:c/cpp 
int Gstate;         //not compliant
int func_GJB_R_01_11_02_basic_01_bad()
{
    static int i;    //not compliant
    if(0 == Gstate)
    {
        i = i + 1;;
    }
    return 0;
}
/*good example*/
int good_Gstate = 0;    //ok
int func_GJB_R_01_11_02_basic_01_good()
{
    static int gi = 0;   //ok
    if(0 == good_Gstate)
    {
        gi = gi + 1;;
    }
    return 0;
}
