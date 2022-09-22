all: item.o Pilha.o main.o
	gcc -g item.o Pilha.o main.o -o exec -std=c99 -Wall; make clean

item.o:
	gcc -g -c item.c -o item.o

Pilha.o:
	gcc -g -c Pilha.c -o Pilha.o
	 
main.o:
	gcc -g -c main.c -o main.o
	 
clean:
	rm *.o

run:
	valgrind ./exec
