CC := g++ -std=c++17
INCDIR := include
SRCDIR := src
OBJDIR := obj
CFLAG := -c -I$(INCDIR)

SRCS := $(wildcard $(SRCDIR)/*.cpp) main.cpp
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

main.x: $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAG) -o $@ $<

clean:
	rm -rf $(OBJDIR)/*.o *.x



#g++ -c -Iinclude main.cpp # produce file oggetto .o di main.cpp
#cd src
#g++ -c -Iinclude Graduate.cpp # produce file oggetto .o di Graduate.cpp
#g++ -c -Iinclude Undergraduated.cpp # produce file oggetto .o di Undergraduated.cpp
#g++ -c -Iinclude Student.cpp # produce file oggetto .o di Student.cpp
#cd ..
#g++ -o main.x main.o ./src/Graduate.o ./src/Undergraduated.o ./src/Student.o # produce l'eseguibile usando tutti i file oggetto necessari
#./main.x
