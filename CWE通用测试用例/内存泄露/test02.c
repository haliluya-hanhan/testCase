//check type:c/cpp
#include <stdlib.h>

enum { BUFFER_SIZE = 32 };

int func_s_06_01_MLK_basic_06_bad(void) {
  char *text_buffer = (char *)malloc(BUFFER_SIZE);	//not compliant
  if (text_buffer == NULL) {
    return -1;
  }
  return 0;
}

//以下是正确得例子。
int func_s_06_01_MLK_basic_06_good(void) {
  char *text_buffer = (char *)malloc(BUFFER_SIZE);
  if (text_buffer == NULL) {
    return -1;
  }

  free(text_buffer);
  return 0;
}
