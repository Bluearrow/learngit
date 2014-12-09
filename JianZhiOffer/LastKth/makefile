CPP = g++
OFLAG = -o
CFLAG = -c

objects = LastKth.o ListHelper.o
target = LastKthTest

ListTest: $(objects)
	$(CPP) $(OFLAG) $(target) $(objects)
LastKth.o: LastKth.cpp ListHelper.h
	$(CPP) $(CFLAG) -g LastKth.cpp
ListHelper.o: ListHelper.cpp
	$(CPP) $(CFLAG) -g ListHelper.cpp
clean:
	rm $(objects) $(target)
