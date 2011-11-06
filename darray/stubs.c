#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>

CAMLprim value caml_create_array(value size, value inc)
{
    CAMLparam2(size, inc);
    CAMLlocal1(ret);
    double d, step;
    int i;
    ret = caml_alloc(Int_val(size), Double_array_tag);
    d = 0.0;
    step = Double_val(inc);
    for(i=0; i<Int_val(size); ++i)
        Store_double_field(ret, i, d + i*step);
    CAMLreturn(ret);
}

CAMLprim value caml_print_array(value a)
{
    CAMLparam1(a);
    int size, i;
    size = Wosize_val(a);
    for(i=0; i<size; ++i)
        printf("%f ", Double_field(a, i));
    printf("\n");
    CAMLreturn(Val_unit);
}
