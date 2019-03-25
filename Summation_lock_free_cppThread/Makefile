CXX=g++
CPPFLAGS=-O3 -Wall --std=c++11
LDLIBS=-pthread
SOURCES=code12.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=code12.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CXX) $(CPPFLAGS) $(LDLIBS) $(SOURCES) -o $@ 


clean:
	rm $(EXECUTABLE)
