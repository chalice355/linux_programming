CX = g++
CXFLAGS = -g -Wall
OBJS = main.o minmax.o
TARGET = minmax

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp minmax.hpp
	$(CX) $(CXFLAGS) -c main.cpp

minmax.o : minmax.cpp minmax.hpp
	$(CX) $(CXFLAGS) -c minmax.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
