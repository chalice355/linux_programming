CX = g++
CXFLAGS = -g -Wall
OBJS = main.o point.o
TARGET = point

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp point.hpp
	$(CX) $(CXFLAGS) -c main.cpp

point.o : point.cpp point.hpp
	$(CX) $(CXFLAGS) -c point.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
