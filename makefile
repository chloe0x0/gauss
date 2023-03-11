CC = g++
CFLAGS = -Wall -Wextra -O2
CLEAN = del # rm on linux 
OBJS = main.o TRAPZ.o

TRAPZ.o: src/TRAPZ.cpp src/TRAPZ.h
	$(CC) $(CFLAGS) -c src/TRAPZ.cpp -o TRAPZ.o

main.o: src/main.cpp src/TRAPZ.h
	$(CC) $(CFLAGS) -c src/main.cpp -o main.o

main: $(OBJS):
	$(CC) $(CFLAGS) $(OBJS) -o main

clean:
	$(CLEAN) *.o