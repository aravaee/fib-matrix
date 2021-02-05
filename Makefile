PROG = main
CC = g++
CPPFLAGS = -g -Wall
OBJS = main.o BigInteger.o fibonacci.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

BigInteger.o: BigInteger.h
	$(CC) $(CPPFLAGS) -c BigInteger.cpp

fibonacci.o: fibonacci.h
	$(CC) $(CPPFLAGS) -c fibonacci.cpp

clean:
	rm -f core $(PROG) $(OBJS)