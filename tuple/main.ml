type t = {first : string; second : float}

external create : string -> float -> t =
    "caml_create"

let _ =
    let r = create "Hello" 3.1415 in
    print_endline r.first;
    print_float r.second;
    print_newline ()
