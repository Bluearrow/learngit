CPP = g++
OFLAG = -o
CFLAG = -c

objects = MergeList.o ListHelper.o
target = MergerListTest

ListTest: $(objects)
	$(CPP) $(OFLAG) $(target) $(objects)
MergeList.o: MergeList.cpp ListHelper.h
ListHelper.o: ListHelper.cpp
clean:
	rm $(objects) $(target)
