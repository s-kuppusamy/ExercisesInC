ex_compile.o: ex_compile.c
	gcc -c ex_compile.c `pkg-config --cflags glib-2.0`
ex_compile: ex_compile.o
	gcc ex_compile.o `pkg-config --libs glib-2.0` -o ex_compile
word_count.o: word_count.c
	gcc -c word_count.c `pkg-config --cflags glib-2.0`
word_count: word_count.o
	gcc word_count.o `pkg-config --libs glib-2.0` -o word_count
