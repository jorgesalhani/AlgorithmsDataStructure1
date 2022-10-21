all: item.o lista.o main.o
	gcc -g item.o lista.o main.o -o exec -std=c99 -Wall; make clean

item.o:
	gcc -g -c item.c -o item.o

lista.o:
	gcc -g -c lista.c -o lista.o
	 
main.o:
	gcc -g -c main.c -o main.o
	 
clean:
	rm *.o

run:
	./exec
