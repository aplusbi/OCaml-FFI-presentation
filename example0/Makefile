main.byte: libstubs.a main.cmo
	ocamlc -o main.byte -custom libstubs.a main.cmo

main.native: libstubs.a main.cmx
	ocamlopt -o main.native libstubs.a main.cmx

dyn.byte: libstubs_so.so main.cmo
	ocamlc -o dyn.byte libstubs_so.so main.cmo

dyn.native: libstubs_so.so main.cmx
	ocamlopt -o dyn.byte libstubs_so.so main.cmx

stubs.o: stubs.c
	gcc -I /usr/local/lib/ocaml -c stubs.c

libstubs.a: stubs.o
	ar rcs libstubs.a stubs.o

stubs_so.o: stubs.c
	gcc -I /usr/local/lib/ocaml -c -fPIC stubs.c -o stubs_so.o

libstubs_so.so:
	gcc -shared -Wl,-soname,libstubs_so.so -o libstubs_so.so

main.cmo: main.ml
	ocamlc -c main.ml

main.cmx: main.ml
	ocamlopt -c main.ml

clean:
	rm stubs.o libstubs.a main.cmo main.cmx main.cmi main.byte main.native
