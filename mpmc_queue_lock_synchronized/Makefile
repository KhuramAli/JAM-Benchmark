CXX=g++
CPPFLAGS=-O3 -Wall --std=c++11
LDLIBS= -lpthread
SOURCES=code06.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=code06.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $@ $(LDLIBS)


clean:
	rm $(EXECUTABLE)
