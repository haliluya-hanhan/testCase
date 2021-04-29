//check type:c/cpp
#include <stdlib.h>

typedef struct x {
   char * field;
  } tx;

void release(tx * a){
      free(a->field);  //
      free(a);         //
 }

int func_s_05_01_UAF_medium_05_bad() {
     tx *a = (tx *)malloc(sizeof(tx));
     if (a==NULL) return 0;
     a->field = (char *)malloc(10);
     release(a);   //not compliant
     free(a->field);     //not
     free(a);            //not
     return 0;
 }


//Ó¦¸ÄÎª£º


int func_s_05_01_UAF_medium_05_good() {
     tx *a = (tx *)malloc(sizeof(tx));
     if (a==NULL) return;
     a->field = (char *)malloc(10);
     release(a);
     return 0;
 }
