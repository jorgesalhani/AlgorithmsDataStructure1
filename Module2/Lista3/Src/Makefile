all: item.o deque.o main.o
	gcc -g item.o deque.o main.o -o exec -Wall -std=c99; make clean

item.o:
	gcc -g item.c -o item.o

deque.o:
	gcc -g deque.c -o deque.o

main.o:
	gcc -g main.c -o main.o

clean:
	rm *.o

run:
	valgrind ./exec