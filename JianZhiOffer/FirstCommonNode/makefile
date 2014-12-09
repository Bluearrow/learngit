CXX = g++
GFLAG = -g
OFLAG = -o
CFLAG = -c

INCLUDE_DIR = -L ./sr/

OBJECTS = ListHelper.o FirstCommonNode.o
TARGET = Test

${TARGET}: ${OBJECTS}
	${CXX} ${OFLAG} ${TARGET} ${OBJECTS}
ListHelper.o: ListHelper.cpp
	${CXX} ${GFLAG} ${CFLAG} ListHelper.cpp
FirstCommonNode.o: FirstCommonNode.cpp ListHelper.h
	${CXX} ${GFLAG} ${CFLAG} ListHelper.h FirstCommonNode.cpp
clean:
	rm ${OBJECTS} ${TARGET}
