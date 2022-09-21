all: item.o Pilha.o main.o
	gcc -g item.o Pilha.o main.o -o exec -std=c99 -Wall; make clean

item.o:
	gcc -c item.c -o item.o

Pilha.o:
	gcc -c Pilha.c -o Pilha.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o

run:
	valgrind ./exec
