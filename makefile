CC = g++
CFLAGS = -Wall -Wextra -O2
CLEAN = del # rm on linux

OBJS = TRAPZ.o

TRAPZ.o: src/TRAPZ.cpp
	$(CC) $(CFLAGS) -c src/TRAPZ.cpp -o TRAPZ.o

gauss.o: $(OBJS)
	$(CC) $(CFLAGS) -c $(OBJS) -o gauss.o

main: gauss.o main.cpp
	$(CC) $(CFLAGS) gauss.o -o main 

clean:
	$(CLEAN) *.o 