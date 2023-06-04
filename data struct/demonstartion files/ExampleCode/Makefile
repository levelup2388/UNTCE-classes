CFLAGS = -O
CC = g++

heapDemo: driver.o itemType.o listType.o
	$(CC) $(CFLAGS) -o heapDemo driver.o itemType.o listType.o

driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp

itemType.o: itemType.cpp
	$(CC) $(CFLAGS) -c itemType.cpp

listType.o: listType.cpp
	$(CC) $(CFLAGS) -c listType.cpp

clean:
	rm -f core *.o
