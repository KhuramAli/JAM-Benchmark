CXX=g++
CPPFLAGS=-O3 -Wall -latomic -std=c++11 
SOURCES=isLockfree.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=isLockfree

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CXX) $(SOURCES) $(CPPFLAGS) -o $@ $(LDLIBS)


clean:
	rm $(EXECUTABLE)
