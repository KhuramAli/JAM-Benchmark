CXX=g++
CXXFLAGS=-O3 -Wall -std=c++17 -lstdc++fs
LDFLAGS= -Llame-3.100\output -lmp3lame -static
LDLIBS=-pthread 
INCLUDE=-Ilame-3.100/include
SRC_DIR=src/
SOURCES=$(SRC_DIR)main.cpp $(SRC_DIR)parsewav.cpp $(SRC_DIR)lameWrapper.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS=$(SRC_DIR)parsewav.h $(SRC_DIR)lameWrapper.h

EXECUTABLE=wav2mp3.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): 
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SOURCES) $(LDFLAGS) $(LDLIBS) -o $@ $^

clean:
	${EXECUTABLE} ${OBJS} *.o *~.
