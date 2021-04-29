//check type:cpp
//Language:CPP
class s_23_03_medium_INFINITE_LOOP_CALL_FUNC_01
{
	private:
    static int x;
    public:
  		s_23_03_medium_INFINITE_LOOP_CALL_FUNC_01()
        {
        	s_23_03_medium_INFINITE_LOOP_CALL_FUNC_01 a = s_23_03_medium_INFINITE_LOOP_CALL_FUNC_01();  //not compliant
        }
};
int func_s_23_03_medium_INFINITE_LOOP_CALL_FUNC_01_good()
{
 	s_23_03_medium_INFINITE_LOOP_CALL_FUNC_01 a;
 	return 0;
}
