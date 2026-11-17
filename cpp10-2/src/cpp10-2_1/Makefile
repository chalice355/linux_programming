CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = box

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp box.hpp
	$(CX) $(CXFLAGS) -c main.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
