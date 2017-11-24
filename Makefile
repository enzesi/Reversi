CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD -g
EXEC = reversi
OBJECTS = main.o cell.o grid.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
