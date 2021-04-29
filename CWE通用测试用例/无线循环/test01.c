//check type:c/cpp
void func_s_23_03_basic_INFINITE_LOOP_CALL_FUNC_01_bad2();

void func_s_23_03_basic_INFINITE_LOOP_CALL_FUNC_01_bad1()  //not compliant
{
	func_s_23_03_basic_INFINITE_LOOP_CALL_FUNC_01_bad2();
}
void func_s_23_03_basic_INFINITE_LOOP_CALL_FUNC_01_bad2()  //not compliant
{
	func_s_23_03_basic_INFINITE_LOOP_CALL_FUNC_01_bad1();
}
int func_s_23_03_basic_INFINITE_LOOP_CALL_FUNC_01()
{
	func_s_23_03_basic_INFINITE_LOOP_CALL_FUNC_01_bad1();
  	return 0;
}
