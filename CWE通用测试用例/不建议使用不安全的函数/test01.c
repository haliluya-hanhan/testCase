//check type:c/cpp 
int func_s_04_01_BANNED_WINDOW_basic_01_bad(){
	unsigned WM_DROPFILES = 0x0233;
	unsigned MSGFLT_ADD = 1;
	ChangeWindowMessageFilter(WM_DROPFILES, MSGFLT_ADD);   //not compliant
	return 0;
}
