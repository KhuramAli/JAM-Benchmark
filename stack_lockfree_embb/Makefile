CXX=g++
CPPFLAGS=-O3 -Wall --std=c++11
LDLIBS=-lembb_dataflow_cpp -lembb_algorithms_cpp -lembb_containers_cpp -lembb_mtapi_cpp -lembb_mtapi_c -lembb_base_cpp -lembb_base_c -lpthread
SOURCES=code05.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=code05.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $@ $(LDLIBS)


clean:
	rm $(EXECUTABLE)
