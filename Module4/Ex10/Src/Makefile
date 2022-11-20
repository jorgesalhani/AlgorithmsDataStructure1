all: item.o abb.o main.o
	gcc -g item.o abb.o main.o -o exec -std=c99 -Wall; make clean

item.o:
	gcc -g -c item.c -o item.o

abb.o:
	gcc -g -c ABB.c -o abb.o
	 
main.o:
	gcc -g -c main.c -o main.o
	 
clean:
	rm *.o

run:
	valgrind ./exec < ../TestCases/3.in