//check type:c/cpp
void reassign(int *argument, int *p) {
    if (*argument>=99) return;
    *argument = *p;           //not compliant
  }

int func_s_30_05_basic_NPD_02_bad()
{
   int *argument;
   reassign(argument, 0);		
   return 0;
 }
