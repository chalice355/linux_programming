CX = g++
CXFLAGS = -g -Wall
OBJS = main.o circle.o
TARGET = circle

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp circle.hpp
	$(CX) $(CXFLAGS) -c main.cpp

circle.o : circle.cpp circle.hpp
	$(CX) $(CXFLAGS) -c circle.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
