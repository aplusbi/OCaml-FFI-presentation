type t =
    | Nothing
    | Int of int
    | Double of float
    | String of string
    | Something
    | Variant of t * t

external variant : t -> unit = "caml_variant"

let _ =
    let v = Variant (Int 5, Variant (String "Hello", Nothing)) in
    variant v
