//check type:c/cpp
//_bug10707
 #include <stdio.h>
 #include <stdlib.h>
 typedef struct CSOUND_  CSOUND;
 typedef int  int32;
 #define Str(x) x
 struct CSOUND_ {
       void *(*FileOpen2)(CSOUND *, void *, int, const char *, const void *,const char *, int, int);
        int (*FileClose)(CSOUND *, void *);
 };

 #    define MYFLT double
  typedef struct event {
    char    *strarg;

  } EVTBLK;
   typedef struct {
    CSOUND  *csound;
    int32   flen;
    int     fno, guardreq;
    EVTBLK  e;
  } FGDATA;
  typedef struct {
    MYFLT   *ftable;
  } FUNC;
  #  define UNLIKELY(x)   x
  #define CSFILE_STD      3
static  int fterror(const FGDATA *ff, const char *s, ...);
static  FUNC *ftalloc(const FGDATA *ff);
static int func_s_06_01_MLK_basic_33_good(FGDATA *ff, FUNC *ftp)
{
    CSOUND  *csound = ff->csound;
    MYFLT   *fp = ftp->ftable, *finp;
    int     seglen, resolution = 100;
    FILE    *filp;
    void    *fd;
    int     i=0, j=0;
    MYFLT   *x, *y, *z;
    int     arraysize = 1000;
    MYFLT   x1, y1, z1, x2, y2, z2, incrx, incry;

    if (UNLIKELY(ff->flen))
      return fterror(ff, Str("GEN28 requires zero table length"));
    fd = csound->FileOpen2(csound, &filp, CSFILE_STD, ff->e.strarg, "r",
                          "SFDIR;SSDIR;INCDIR", 56, 0);
    if (UNLIKELY(fd == NULL))
      goto gen28err1;

    x = (MYFLT*)malloc(arraysize*sizeof(MYFLT));
    y = (MYFLT*)malloc(arraysize*sizeof(MYFLT));
    z = (MYFLT*)malloc(arraysize*sizeof(MYFLT));
#if defined(USE_DOUBLE)
    while (fscanf( filp, "%lf%lf%lf", &z[i], &x[i], &y[i])!= EOF)
#else
    while (fscanf( filp, "%f%f%f", &z[i], &x[i], &y[i])!= EOF)
#endif
      {
        i++;
        if (i>=arraysize) {
          MYFLT* newx, *newy, *newz;
          arraysize += 1000;
          newx = (MYFLT*)realloc(x, arraysize*sizeof(MYFLT));
          newy = (MYFLT*)realloc(y, arraysize*sizeof(MYFLT));
          newz = (MYFLT*)realloc(z, arraysize*sizeof(MYFLT));
          if (!newx || !newy || !newz) {
            fprintf(stderr, Str("Out of Memory\n"));
            exit(7);
          }
          x = newx; y = newy; z = newz;   //newx，newy，newz分别赋给 x , y ,z
        }
      }
    --i;

    ff->flen      = (int32) (z[i] * resolution * 2);
    ff->flen      = ff->flen + 2;       /* ??? */
    ftp           = ftalloc(ff);
    fp            = ftp->ftable;
    finp          = fp + ff->flen;

    do {
      x1 = x[j];
      y1 = y[j];
      x2 = x[j+1];
      y2 = y[j+1];
      z1 = z[j];
      z2 = z[j+1];

      if (UNLIKELY(z2 < z1)) goto gen28err2;
      seglen = (int)((z2-z1) * resolution);
      incrx = (x2 - x1) / (MYFLT)seglen;
      incry = (y2 - y1) / (MYFLT)seglen;
      while (seglen--) {
        *fp++ = x1;
        x1   += incrx;
        *fp++ = y1;
        y1   += incry;
      }

      j++;
    } while (--i);
    do {
      *fp++ = x[j];
      *fp++ = y[j+1];
    } while (fp < finp);

    free(x); free(y); free(z);
    csound->FileClose(csound, fd);

    return 0;

 gen28err1:
    return fterror(ff, Str("could not open space file"));
 gen28err2:
    free(x); free(y); free(z);               //x,y,z都释放了内存-误报
    return fterror(ff, Str("Time values must be in increasing order"));
}
