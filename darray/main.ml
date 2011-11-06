external create_array : int -> float ->
    float array = "caml_create_array"
external print_array : float array -> unit =
    "caml_print_array"

let _ =
    let a = create_array 5 0.5 in
    print_array a
