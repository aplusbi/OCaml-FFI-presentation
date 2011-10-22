external double_add : float -> float -> float = "caml_double_add"

let _ =
    let pi = double_add 3.0 0.1415 in
    print_float pi;
    print_newline ()
