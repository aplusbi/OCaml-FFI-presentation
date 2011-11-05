external print_array : int array -> unit =
    "caml_print_array"

let _ =
    let a = [|1; 2; 3; 4; 5|] in
    print_array a
