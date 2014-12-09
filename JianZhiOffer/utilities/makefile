CPP = g++
OFLAG = -o
CFLAG = -c

objects = main.o ListHelper.o
target = ListTest

ListTest: $(objects)
	$(CPP) $(OFLAG) $(target) $(objects)
main.o: main.cpp ListHelper.h
	$(CPP) $(CFLAG) -g main.cpp
ListHelper.o: ListHelper.cpp
	$(CPP) $(CFLAG) -g ListHelper.cpp
clean:
	rm $(objects) $(target)
