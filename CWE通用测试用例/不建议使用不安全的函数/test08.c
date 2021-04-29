//check type:c/cpp 
#include <stdlib.h>
#include <stdio.h>
void func_s_04_08_BANNED_SCANF_basic_01_bad( void )
{
   int   i, result;
   float fp;
   char  c, s[81];
   wchar_t wc, ws[81];

   printf( "\n\nEnter an int, a float, two chars and two strings\n");

   result = scanf( "%d %f %c %C %s %S", &i, &fp, &c, &wc, s, ws );    //not compliant
   printf( "\nThe number of fields input is %d\n", result );
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);

   wprintf( L"\n\nEnter an int, a float, two chars and two strings\n");

   result = wscanf( L"%d %f %hc %lc %S %ls", &i, &fp, &c, &wc, s, ws );       //not compliant
   wprintf( L"\nThe number of fields input is %d\n", result );
   wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp, c, wc, s, ws);
}
