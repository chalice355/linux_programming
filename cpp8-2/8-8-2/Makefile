CX = g++
CXFLAGS = -g -Wall
OBJS = main.o tv.o
TARGET = tv

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp tv.hpp
	$(CX) $(CXFLAGS) -c main.cpp

tv.o : tv.cpp tv.hpp
	$(CX) $(CXFLAGS) -c tv.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
