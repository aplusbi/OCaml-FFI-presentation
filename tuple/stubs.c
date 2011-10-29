#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>

CAMLprim value caml_create(value str, value fl) {
    CAMLparam2(str, fl);
    CAMLlocal1(ret);

    ret = caml_alloc_tuple(2);
    Field(ret, 0) = str;
    Field(ret, 1) = fl;

    CAMLreturn(ret);
}
