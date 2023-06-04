CFLAGS = -O
CC = g++

insert2: driver.o itemType.o listType.o
	$(CC) $(CFLAGS) -o insert2 driver.o itemType.o listType.o

driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp

itemType.o: itemType.cpp
	$(CC) $(CFLAGS) -c itemType.cpp

listType.o: listType.cpp
	$(CC) $(CFLAGS) -c listType.cpp

clean:
	rm -f core *.o
