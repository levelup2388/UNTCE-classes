newshell: major2.o batchMode.o
	gcc -o newshell major2.o batchMode.o

major2.o: major2.c
	gcc -c -Wall major2.c

batchMode.o: batchMode.c
	gcc -c -Wall batchMode.c

clean:
	rm -f core *.o
