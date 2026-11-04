CX = g++
CXFLAGS = -g -Wall
OBJS = main.o shape.o
TARGET = shapes

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp shape.hpp
	$(CX) $(CXFLAGS) -c main.cpp

shape.o : shape.cpp shape.hpp
	$(CX) $(CXFLAGS) -c shape.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
