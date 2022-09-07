all: book.o client.o run
	gcc client.o book.o -o exec -std=c99 -Wall; make clean

scheduling.o:
	gcc -c scheduling.c -o scheduling.o

book.o:
	gcc -c book.c -o book.o

client.o:
	gcc -c client.c -o client.o

clean:
	rm *.o exec
	
run:
	./exec