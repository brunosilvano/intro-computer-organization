CC = gcc

CFLAGS = -g -Wall
CLIBS = -lwiringPi

echoDecHex: echoDecHex.c
	$(CC) $(CFLAGS) -o $@ $^

decToBin: decToBin.c
	$(CC) $(CFLAGS) -o $@ $^

2.16.1: 2.16.1.c
	$(CC) $(CFLAGS) -o $@ $^

2.16.2: 2.16.2.c
	$(CC) $(CFLAGS) -o $@ $^

2.16.3: 2.16.3.c
	$(CC) $(CFLAGS) -o $@ $^

2.17: 2.17.c
	$(CC) $(CFLAGS) $(CLIBS) -o $@ $^
