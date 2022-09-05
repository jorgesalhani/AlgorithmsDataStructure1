all: scheduling.o shelf.o client.o
	gcc client.o shelf.o scheduling.o -o exec -std=c99 -Wall

scheduling.o:
	gcc -c scheduling.c -o scheduling.o

shelf.o:
	gcc -c shelf.c -o shelf.o

client.o:
	gcc -c client.c -o client.o

clean:
	rm *.o exec
	
run:
	./exec