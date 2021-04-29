//check type:cpp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//from huawei漏报
typedef signed int INT32;
typedef unsigned short UINT8;
typedef unsigned int UINT32;
static INT32 aep_debugnum()
{
	if(NULL==0){
		return 0;
	}
	return 1;
}

void  s_30_03_basic_LIB_NPD_8(char *v8){
  INT32 v10=0;
  INT32 v24=0;
  UINT8 *ptr = NULL;
  UINT32 v15=0;
  char *v9;
  UINT32 v11=0;
  UINT32 v13 = 0;
	if(NULL==v8){
	  return;
	}

v9 = strchr(v8,'('); 
v10 = aep_debugnum();
if(!v10){
if(!v24){
	v11=0;
do{ 
	if(!(NULL==ptr)){
		 goto Label_11;
	} 
	v15 = *(UINT32 *)((char *)ptr+v10);
	if(v15>0)
		printf("sssssssssssss");
	++v11;
	v10+=4;
	printf("func[%s]  line [%d] pcIp = %s.\n", "Dev",1631,v9);   //not compliant
} while(v11<v24);
Label_11:
if(!v13){
	return;
}
}
}
}
int main(int argc, char* argv[]) {
	char* a = argv[0];
	s_30_03_basic_LIB_NPD_8(a);
}