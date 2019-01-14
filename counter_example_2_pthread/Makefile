CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-pthread
SOURCES=code02.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=code02

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE)
