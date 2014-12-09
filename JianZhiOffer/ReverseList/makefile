CPP = g++
OFLAG = -o
CFLAG = -c

objects = ReverseList.o ListHelper.o
target = ReverseListTest

ListTest: $(objects)
	$(CPP) $(OFLAG) $(target) $(objects)
ReverseList.o: ReverseList.cpp ListHelper.h
	$(CPP) $(CFLAG) -g ReverseList.cpp
ListHelper.o: ListHelper.cpp
	$(CPP) $(CFLAG) -g ListHelper.cpp
clean:
	rm $(objects) $(target)
