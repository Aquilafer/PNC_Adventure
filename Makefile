ALL: game

PROJDIR := $(CURDIR)
SRCDIR := $(PROJDIR)/src
OBJDIR := $(PROJDIR)/obj
BINDIR := $(PROJDIR)/bin
TESTDIR := $(PROJDIR)/test

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard $(SRCDIR)/*.hpp)

OBJECTS := $(subst $(SRCDIR),$(OBJDIR),$(SOURCES:.cpp=.o))

$(OBJECTS) : $(SOURCES) ${HEADERS}
	g++ -c $< -o $@

game: ${OBJECTS}
	g++ -o $(BINDIR)/$@ ${OBJECTS}

clean:
	rm $(OBJDIR)/* $(BINDIR)/*
