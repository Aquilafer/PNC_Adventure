ALL: game

PROJDIR := $(CURDIR)
SRCDIR := $(PROJDIR)/src
OBJDIR := $(PROJDIR)/obj
BINDIR := $(PROJDIR)/bin
TESTDIR := $(PROJDIR)/test

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard $(SRCDIR)/*.hpp)

OBJECTS := $(subst $(SRCDIR),$(OBJDIR),$(SOURCES:.cpp=.o))

DEBUG ?= FALSE

CXX_FLAGS := -Wall -Wpedantic
OBJ_FLAGS :=  `pkg-config gtkmm-3.0 --cflags --libs`
EXE_FLAGS :=  `pkg-config gtkmm-3.0 --cflags --libs`

ifeq ($(DEBUG), TRUE)
	CXXFLAGS += -g
else
	CXXFLAGS += -DNDEBUG -O3
endif

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	g++ $(CXXFLAGS) -c $< -o $@ ${OBJ_FLAGS}

game: ${OBJECTS}
	g++ $(CXXFLAGS) -o $(BINDIR)/$@ ${OBJECTS} ${EXE_FLAGS}

clean:
	rm -r $(OBJDIR) $(BINDIR)
	mkdir $(OBJDIR)
	mkdir $(BINDIR)
