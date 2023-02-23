CC := g++ -std=c++17
INCDIR := include
CFLAG := -c -I$(INCDIR)

main.x: main.o
	$(CC) -o $@ $^
main.o: main.cpp ./include/*
	$(CC) $(CFLAG) $<
clean:
	rm -rf *.o *.x