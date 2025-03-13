CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test valgrind

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) llrec-test.o llrec.o -o llrec-test

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

valgrind: llrec-test
	$(VALGRIND) ./llrec-test llrec-test1.in

	


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 