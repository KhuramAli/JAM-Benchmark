CXX=g++
CPPFLAGS=-O3 -Wall --std=c++11
LDLIBS=-lembb_dataflow_cpp -lpthread
SOURCES=code05.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=code05.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $@ $(LDLIBS)


clean:
	rm $(EXECUTABLE)
