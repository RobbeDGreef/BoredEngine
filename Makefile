CPP_FILES=$(shell find ./src -name "*.cpp" -type f)
CPP_OBJECTS=${CPP_FILES:.cpp=.o}

GPP=g++
GPPFLAGS= -g -lsfml-graphics -lsfml-window -lsfml-system -I ./include -I ./config -D DEBUG_BUILD

all: BoredEngine

BoredEngine: ${CPP_OBJECTS}
	$(GPP) ${GPPFLAGS} $^ -o $@

%.o: %.cpp
	$(GPP) ${GPPFLAGS} -c $< -o $@ 

clean:
	rm -rf ${CPP_OBJECTS}
	rm -f BoredEngine