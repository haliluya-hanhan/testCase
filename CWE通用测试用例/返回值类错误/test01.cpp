//check type:cpp
/*局部变量地址赋值给public成员变量*/
class A {
	public:
		char* p;
		void func_s_37_01_meidum_RETURN_LOCAL_03_bad() {
			char a;
			p = 0;
			p = &a;  //not
			*p = 0;
		}    //not compliant
		void g() {
			*p = '0';
		}
};
void func_s_37_01_meidum_RETURN_LOCAL_03() {
    A a;
    a.func_s_37_01_meidum_RETURN_LOCAL_03_bad();
    a.g();
}
