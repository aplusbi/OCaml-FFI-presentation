open Bigarray

external create_ba : int -> int ->
    (int, int64_elt, c_layout) Array2.t = "caml_create_ba"

external print_ba : (int, int64_elt, c_layout) Array2.t -> unit
    = "caml_print_ba"

let _ =
    let ba = create_ba 5 5 in
    print_ba ba
