CC = g++ -std=c++17
INCDIR = include
SRCDIR = src
OBJDIR = obj
CFLAG = -c -I$(INCDIR)

SRCS := $(wildcard $(SRCDIR)/*.cpp) main.cpp
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

main.x: $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAG) -o $@ $<

clean:
	rm -rf $(OBJDIR)/*.o *.x