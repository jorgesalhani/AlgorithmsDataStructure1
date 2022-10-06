all: fila.o item.o main.o
	gcc item.o fila.o main.o -o exec -std=c99 -Wall; make clean

fila.o:
	gcc -g -c fila.c -o fila.o

item.o:
	gcc -g -c item.c -o item.o

main.o:
	gcc -g -c main.c -o main.o

clean:
	rm *.o

run:
	valgrind ./exec