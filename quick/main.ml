external add : int -> int -> int = "caml_add"

let _ =
    let three = add 1 2 in
    print_int three;
    print_newline ()
