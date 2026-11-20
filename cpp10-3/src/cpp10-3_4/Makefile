CX = g++
CXFLAGS = -g -Wall
OBJS = main.o vecavg.o
TARGET = vecavg

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp vecavg.hpp
	$(CX) $(CXFLAGS) -c main.cpp

vecavg.o : vecavg.cpp vecavg.hpp
	$(CX) $(CXFLAGS) -c vecavg.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
