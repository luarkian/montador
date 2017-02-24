main:	main.o	montador.o
	gcc main.o montador.o -o main

main.o: main.c
	gcc -c main.c

montador.o:	montador.c	montador.h
	gcc -c montador.c

clean:
	rm *.o
