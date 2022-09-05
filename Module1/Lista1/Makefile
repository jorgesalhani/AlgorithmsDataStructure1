all: scheduling.o shelf.o client.o
	gcc client.o shelf.o scheduling.o -o shelf_borrow -std=c99 -Wall

scheduling.o:
	gcc -c scheduling.c -o scheduling.o

shelf.o:
	gcc -c shelf.c -o shelf.o

client.o:
	gcc -c client.c -o client.o

clean:
	rm *.o shelf_borrow
	
run:
	./shelf_borrow