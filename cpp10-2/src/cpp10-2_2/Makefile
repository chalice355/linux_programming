CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = gclass

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp gclass.hpp
	$(CX) $(CXFLAGS) -c main.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
