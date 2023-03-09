CC = g++
CFLAGS = -Wall -Wextra -O2
CLEAN = del # rm on linux

OBJS = TRAPZ.o

TRAPZ.o: src/TRAPZ.cpp
	$(CC) $(CFLAGS) -c src/TRAPZ.cpp -o TRAPZ.o

gauss: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o gauss

clean:
	$(CLEAN) *.o 
	$(CLEAN) *.exe