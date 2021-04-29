//check type:c/cpp
//_bug10852
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
# define MAXPATHLEN	4096
#define _PyObject_HEAD_EXTRA
typedef ssize_t         Py_ssize_t;
typedef struct _typeobject {
    unsigned long tp_flags;
}PyTypeObject;
typedef struct _object {
    _PyObject_HEAD_EXTRA
    Py_ssize_t ob_refcnt;
    struct _typeobject *ob_type;
} PyObject;
typedef struct {
    const char *function_name;
    const char *argument_name;
    int nullable;
    int allow_fd;
    wchar_t *wide;
    char *narrow;
    int fd;
    Py_ssize_t length;
    PyObject *object;
    PyObject *cleanup;
} path_t;
#define DEFAULT_DIR_FD (-100)
#       define PyAPI_FUNC(RTYPE) RTYPE
#define PyArg_ParseTupleAndKeywords	_PyArg_ParseTupleAndKeywords_SizeT
PyAPI_FUNC(int) PyArg_ParseTupleAndKeywords(PyObject *, PyObject *,
                                                  const char *, char **, ...);
static int
path_converter(PyObject *o, void *p)
{

}
static int
dir_fd_converter(PyObject *o, void *p){}
#define Py_TPFLAGS_UNICODE_SUBCLASS     (1UL << 28)
#define HAVE_READLINKAT 1
#define Py_TYPE(ob)             (((PyObject*)(ob))->ob_type)
#define PyType_HasFeature(t,f)  (((t)->tp_flags & (f)) != 0)
#define PyType_FastSubclass(t,f)  PyType_HasFeature(t,f)
#define PyUnicode_Check(op) \
                 PyType_FastSubclass(Py_TYPE(op), Py_TPFLAGS_UNICODE_SUBCLASS)
                 PyObject*
func_s_19_02_medium_NNTS_TAINTED_02_bad(const char *str, Py_ssize_t len,
                              const char *errors)
{


    if (str[len] != '\0' || len != strlen(str)) {  //not compliant str[len]可能无结束符
        return NULL;
    }

    return NULL;
}
typedef struct _is {

    struct _is *next;
    struct _ts *tstate_head;

    PyObject *modules;
    PyObject *modules_by_index;
    PyObject *sysdict;
    PyObject *builtins;
    PyObject *importlib;

    PyObject *codec_search_path;
    PyObject *codec_search_cache;
    PyObject *codec_error_registry;
    int codecs_initialized;
    int fscodec_initialized;
    int dlopenflags;
    PyObject *builtins_copy;
} PyInterpreterState;
typedef struct _ts {
    PyInterpreterState *interp;
} PyThreadState;
typedef struct _Py_atomic_address {
    void *_value;
} _Py_atomic_address;
typedef enum _Py_memory_order {
    _Py_memory_order_relaxed,
    _Py_memory_order_acquire,
    _Py_memory_order_release,
    _Py_memory_order_acq_rel,
    _Py_memory_order_seq_cst
} _Py_memory_order;
#define PyAPI_DATA(RTYPE) extern RTYPE
PyAPI_DATA(_Py_atomic_address) _PyThreadState_Current;
PyAPI_DATA(const char *) Py_FileSystemDefaultEncoding;
#define _Py_atomic_load_explicit(ATOMIC_VAL, ORDER) \
    ((ATOMIC_VAL)->_value)
#define _Py_atomic_load_relaxed(ATOMIC_VAL) \
    _Py_atomic_load_explicit(ATOMIC_VAL, _Py_memory_order_relaxed)
#define PyThreadState_GET() \
    ((PyThreadState*)_Py_atomic_load_relaxed(&_PyThreadState_Current))
PyObject *
PyUnicode_Decode(const char *s,
                 Py_ssize_t size,
                 const char *encoding,
                 const char *errors){}
PyObject*
PyUnicode_DecodeFSDefaultAndSize(const char *s, Py_ssize_t size)
{

    PyInterpreterState *interp = PyThreadState_GET()->interp;

    if (Py_FileSystemDefaultEncoding && interp->fscodec_initialized) {
        return PyUnicode_Decode(s, size,
                                Py_FileSystemDefaultEncoding,
                                "surrogateescape");
    }
    else {
        return func_s_19_02_medium_NNTS_TAINTED_02_bad(s, size, "surrogateescape"); //调用此函数
    }

}
PyObject *
PyBytes_FromStringAndSize(const char *str, Py_ssize_t size)
{

}
static PyObject *
posix_readlink(PyObject *self, PyObject *args, PyObject *kwargs)
{
    path_t path;
    int dir_fd = DEFAULT_DIR_FD;
    char buffer[MAXPATHLEN];
    ssize_t length;
    PyObject *return_value = NULL;
    static char *keywords[] = {"path", "dir_fd", NULL};

    memset(&path, 0, sizeof(path));
    path.function_name = "readlink";
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O&|$O&:readlink", keywords,
                          path_converter, &path,
#ifdef HAVE_READLINKAT
                          dir_fd_converter, &dir_fd
#else
                          dir_fd_unavailable, &dir_fd
#endif
                          ))
        return NULL;

#ifdef HAVE_READLINKAT
    if (dir_fd != DEFAULT_DIR_FD)
        length = readlinkat(dir_fd, path.narrow, buffer, sizeof(buffer));
    else
#endif
        length = readlink(path.narrow, buffer, sizeof(buffer));  //readlink无结束符


    if (length < 0) {
        goto exit;
    }

    if (PyUnicode_Check(path.object))
        return_value = PyUnicode_DecodeFSDefaultAndSize(buffer, length); //调用函数
    else
        return_value = PyBytes_FromStringAndSize(buffer, length);
exit:
    return return_value;
}
