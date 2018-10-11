CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -Werror=vla
OBJECTS=main.o cell.o grid.o textdisplay.o GeneralInfo.o block.o level.o level0.o level1.o level2.o level3.o level4.o iblock.o oblock.o jblock.o sblock.o lblock.o tblock.o zblock.o graphicsdisplay.o window.o subject.o nullblock.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=quadris
${EXEC}:        ${OBJECTS}
	${CXX}  ${CXXFLAGS}	${OBJECTS}	-o	${EXEC} -lX11
-include        ${DEPENDS}
PHONY:  clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
