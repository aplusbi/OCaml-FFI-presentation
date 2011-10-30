#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>

CAMLprim value caml_print_list(value list) {
    CAMLparam1(list);
    CAMLlocal2(head, tail);

    if(Is_block(list))
    {
        head = Field(list, 0);
        tail = Field(list, 1);
        printf("%d ", Int_val(head));
        CAMLreturn(caml_print_list(tail));
    }

    printf("\n");
    CAMLreturn(Val_unit);
}

