#include <caml/memory.h>
#include <caml/mlvalues.h>

CAMLprim value caml_add(value a, value b)
{
    CAMLparam2(a, b);
    int c;
    c = Int_val(a) + Int_val(b);
    CAMLreturn(Val_int(c));
}

