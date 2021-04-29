//check type:c/cpp
/*example01*/
#define begin 5 //
#define end 3  //
void func_s_23_04_basic_INFINITE_LOOP_LOGICAL_02_bad1() {
  int i;
  for (i = begin; i != end; ++i) {   //not compliant
    /* ... */
  }
}
/*example02*/
#define begin 3  //
#define end 5    //
void func_s_23_04_basic_INFINITE_LOOP_LOGICAL_02_bad2() {
  int i;
  for (i = begin; i != end; --i) {   //not compliant
    /* ... */
  }
}
