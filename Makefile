all: clean
	g++ -g -std=c++11  -c templated_inheritance.cpp Table.h Column.h Object.h DataColumnFactory.h
	g++ -g -std=c++11 -o out templated_inheritance.o
clean:
	rm -f out
	rm -f *.o
	rm -f *.gch
