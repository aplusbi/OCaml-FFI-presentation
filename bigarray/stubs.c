#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/bigarray.h>

CAMLprim value caml_create_ba(value w, value h)
{
    CAMLparam2(w, h);
    CAMLlocal1(ret);
    int i, width, height;
    long *data;

    width = Int_val(w);
    height = Int_val(h);
    /* oh noes!  leaking memory! */
    data = malloc(sizeof(long)*width*height);
    for(i=0; i<width*height; ++i)
        data[i] = i;
    ret = caml_ba_alloc_dims(CAML_BA_INT64 | CAML_BA_C_LAYOUT,
            2, data, width, height);
    CAMLreturn(ret);
}

CAMLprim value caml_print_ba(value ba)
{
    CAMLparam1(ba);
    int width, height;
    int x, y;
    long *data;
    width = Caml_ba_array_val(ba)->dim[0];
    height = Caml_ba_array_val(ba)->dim[1];
    data = Caml_ba_data_val(ba);
    for(y=0; y<height; ++y) {
        for(x=0; x<width; ++x) {
            printf("%d ", data[y*width + x]);
        }
        printf("\n");
    }
    CAMLreturn(Val_unit);
}

