
ex_compile.o: ex_compile.c
    gcc -c ex_compile.c `pkg-config --cflags --libs glib-2.0`

ex_compile: ex_compile.o
  gcc ex_compile.o -o ex_compile
