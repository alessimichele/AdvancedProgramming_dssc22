CC = g++ -std=c++17

INCDIR = include

CFLAGS = -c -I$(INCDIR)

main.x: main.o
	$(CC) -o $@ $^
main.o: main.cpp ./include/*
	$(CC) $(CFLAGS) $<
clean:
	rm -rf *.o *.x 

# ./include/static_array.hpp ./include/dynamic_array.hpp ./include/array.hpp ./include/vector.hpp ./include/unique.hpp
# this line fa si che gli header siano consideati dependencies per main.o.
# quindi se un header viene modificato, e esego 'make', verrà ricompilato il codice oggetto con lheader modficato

# ./include/* serve a scrivere quella linea in modo piu compatto " considera come dependecy tutto cio che è dentro include