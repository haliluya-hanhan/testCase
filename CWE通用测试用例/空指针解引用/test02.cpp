//check type:cpp
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char   BYTE;
int SaveRGBFile(const char* pFileName, int m_iRgbSize)
{
    BYTE* pBuffer = new BYTE[m_iRgbSize];

    FILE* fp = fopen(pFileName, "wb");  
    fwrite(pBuffer, m_iRgbSize, 1, fp);  //not compliant
    fclose(fp);

    delete []pBuffer;
    return 0;
}
