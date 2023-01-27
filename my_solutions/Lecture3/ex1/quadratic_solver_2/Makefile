CC = g++

INCDIR = include

OBJDIR = obj

CFLAGS = -c -I$(INCDIR)

OBJECTS = main.o $(OBJDIR)/coeff.o $(OBJDIR)/CQuadraticEq.o

target.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf obj/*.o *.x
