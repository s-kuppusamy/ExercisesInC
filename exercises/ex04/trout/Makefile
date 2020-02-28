util.o: util.c util.h
	gcc -c util.c -Wall
trout.o: trout.c trout.h util.h
	gcc -c trout.c -Wall
main.o: main.c trout.h util.h
	gcc -c main.c -Wall
trout: main.o trout.o util.o
	gcc main.o trout.o util.o -o trout -Wall
