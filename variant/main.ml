type t =
    | Nothing (* Val_int(0) *)
    | Int of int (* Block with tag 0 *)
    | Double of float (* Block with tag 1 *)
    | String of string (* Block with tag 2 *)
    | Something (* Val_int(1) *)
    | Variant of t * t (* Block with tag 3 *)

external variant : t -> unit = "caml_variant"

let _ =
    let v = Variant (Int 5,
        Variant (String "Hello",
        Nothing)) in
    variant v
