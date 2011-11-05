#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>

CAMLprim value caml_print_array(value a)
{
    CAMLparam1(a);
    int size, i;
    size = Wosize_val(a);
    for(i=0; i<size; ++i)
        printf("%d ", Int_val(Field(a, i)));
    printf("\n");
    CAMLreturn(Val_unit);
}
