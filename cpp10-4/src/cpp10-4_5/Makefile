CX = g++
CXFLAGS = -g -Wall
OBJS = main.o student.o
TARGET = student

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)

main.o : main.cpp student.hpp
	$(CX) $(CXFLAGS) -c main.cpp

student.o : student.cpp student.hpp
	$(CX) $(CXFLAGS) -c student.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
