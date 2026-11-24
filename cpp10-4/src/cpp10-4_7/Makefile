CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = mysort

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp mysort.hpp
	$(CX) $(CXFLAGS) -c main.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
