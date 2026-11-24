CX = g++
CXFLAGS = -g -Wall
OBJS = main.o vecprint.o
TARGET = sorting

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp vecprint.hpp
	$(CX) $(CXFLAGS) -c main.cpp

vecprint.o : vecprint.cpp vecprint.hpp
	$(CX) $(CXFLAGS) -c vecprint.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
