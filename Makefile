# ******************************************************************************
# Project's directories
# ******************************************************************************

SRCDIR = src/
EXEDIR = bin/
BUILDDIR = build/
LIBDIR = lib/
INCLUDEDIR = include/


# ******************************************************************************
# Variables for compiler & compiling and linking options
# ******************************************************************************

CC=g++
CFLAGS=-g -O3 -Wall -std=c++1y -I$(INCLUDEDIR)
LDFLAGS=-L$(LIBDIR)
LIB=-lcppformat


# ******************************************************************************
# Project's sources & objects files
# ******************************************************************************

SOURCES=$(wildcard $(SRCDIR)*.cpp)
OBJECTS=$(addprefix $(BUILDDIR),$(notdir $(SOURCES:.cpp=.o)))


# ******************************************************************************
# Test files
# ******************************************************************************

TESTPROG = test
TESTDIR = tests/
TESTSOURCE = $(TESTDIR)$(TESTPROG).cpp
TESTOBJECT = $(BUILDDIR)$(TESTPROG).o
EXECUTABLE=$(EXEDIR)$(TESTPROG)

test: $(EXECUTABLE)
.PHONY: test

$(EXECUTABLE): $(OBJECTS) $(TESTOBJECT)
	$(CC) $(LDFLAGS) $(OBJECTS) $(TESTOBJECT) -o $(EXEDIR)$(TESTPROG) $(LIB)
	
$(BUILDDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $< -c -o $@
	
$(TESTOBJECT): $(TESTSOURCE)
	$(CC) $(CFLAGS) $< -c -o $@
	

# ******************************************************************************
# Clean project files
# ******************************************************************************
clean:
	rm -f $(OBJECTS) $(TESTOBJECT) $(EXECUTABLE) 
.PHONY: clean
