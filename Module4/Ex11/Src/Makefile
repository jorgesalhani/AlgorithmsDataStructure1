all: item.o ab.o main.o
	gcc -g item.o ab.o main.o -o exec -std=c99 -Wall; make clean

item.o:
	gcc -g -c item.c -o item.o

ab.o:
	gcc -g -c ab.c -o ab.o
	 
main.o:
	gcc -g -c main.c -o main.o
	 
clean:
	rm *.o

run:
	valgrind ./exec < ../TestCases/1.in