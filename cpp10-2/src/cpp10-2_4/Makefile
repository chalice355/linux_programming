CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = myqueue

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp myqueue.hpp
	$(CX) $(CXFLAGS) -c main.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
