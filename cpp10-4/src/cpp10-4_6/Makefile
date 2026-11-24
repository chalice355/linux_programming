CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = myalgo

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp myalgo.hpp
	$(CX) $(CXFLAGS) -c main.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
