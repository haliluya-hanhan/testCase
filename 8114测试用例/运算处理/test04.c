//check type:c/cpp
int func_GJB_R_01_06_01_basic_2_bad(void)
{
  unsigned short udata = 2.5; //not compliant 
  udata = udata + 1;
  return 0;
}
int func_GJB_R_01_06_01_basic_2_good(void)
{
    unsigned short udata = 3;          // ok-1
    udata = udata + 1;
    return 0;
}
