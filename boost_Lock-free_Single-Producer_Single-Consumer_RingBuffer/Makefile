CXX=g++
CPPFLAGS=-O3 -Wall --std=c++11
LDLIBS=-pthread -lboost_system -lboost_thread
SOURCES=code10.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=code10

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CXX) $(CPPFLAGS) $(LDLIBS) $(SOURCES) -o $@ 


clean:
	rm $(EXECUTABLE)
