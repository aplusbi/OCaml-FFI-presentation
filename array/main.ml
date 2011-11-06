external create_array : int -> int array =
    "caml_create_array"
external print_array : int array -> unit =
    "caml_print_array"

let _ =
    let a = create_array 5 in
    print_array a
