CFLAGS = -O
CC = g++

cntDemo: driver.o counter.o
	$(CC) $(CFLAGS) -o cntDemo driver.o counter.o

driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp

counter.o: counter.cpp
	$(CC) $(CFLAGS) -c counter.cpp

clean:
	rm -f core *.o
