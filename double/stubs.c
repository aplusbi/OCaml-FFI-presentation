#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>

CAMLprim value caml_double_add(value dbl1,
        value dbl2)
{
    CAMLparam2(dbl1, dbl2);
    CAMLlocal1(ret);
    double d;
    d = Double_val(dbl1) + Double_val(dbl2);
    ret = caml_copy_double(d);
    CAMLreturn(ret);
}
