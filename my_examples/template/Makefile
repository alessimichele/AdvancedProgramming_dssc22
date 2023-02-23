CC = g++ -std=c++17

INCDIR = include

CFLAGS = -c -I$(INCDIR)

main.x: main.o
	$(CC) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm -rf *.o *.x