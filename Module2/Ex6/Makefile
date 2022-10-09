all: item.o fila.o main.o
	gcc -g item.o fila.o main.o -o exec -std=c99 -Wall; make clean;

item.o:
	gcc -g -c item.c -o item.o

fila.o:
	gcc -g -c fila.c -o fila.o

main.o:
	gcc -g -c main.c -o main.o
	 
clean:
	rm *.o

run:
	valgrind ./exec < CasosTeste/5.in
