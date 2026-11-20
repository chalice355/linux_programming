CX = g++
CXFLAGS = -g -Wall
OBJS = main.o words.o
TARGET = words

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp words.hpp
	$(CX) $(CXFLAGS) -c main.cpp

words.o : words.cpp words.hpp
	$(CX) $(CXFLAGS) -c words.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
