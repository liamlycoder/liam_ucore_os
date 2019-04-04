run: main.o linklist.c
	gcc main.o linklist.c -o run
run2: main2.o linklist.c	
	gcc main2.o	linklist.c -o run2
main.o: main.c
	gcc -c main.c -o main.o
main2.o: main2.c
	gcc -c main2.c -o main2.o
linklist.o: linklist.c
	gcc -c linklist.c -o linklist.o
.PHONY: clean
clean:
	rm *.o
	rm run

