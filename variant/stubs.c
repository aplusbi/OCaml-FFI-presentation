#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>

CAMLprim value caml_variant(value t) {
    CAMLparam1(t);
    if(Is_block(t)) {
        switch(Tag_val(t)) {
            case 0:
                printf("Int of %d\n", Int_val(Field(t, 0)));
                break;
            case 1:
                printf("Double of %f\n", Double_val(Field(t, 0)));
                break;
            case 2:
                printf("String of %s\n", String_val(Field(t, 0)));
                break;
            case 3:
                printf("Begin Variant of\n");
                caml_variant(Field(t, 0));
                caml_variant(Field(t, 1));
                printf("Variant\n");
                break;
        }
    }
    else {
        if(Int_val(t) == 0)
            printf("Nothing\n");
        else if(Int_val(t) == 1)
            printf("Something\n");
    }
    CAMLreturn(Val_unit);
}
