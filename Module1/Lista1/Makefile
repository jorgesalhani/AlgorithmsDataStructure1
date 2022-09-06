all: scheduling.o book.o client.o
	gcc client.o book.o scheduling.o -o exec -std=c99 -Wall

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