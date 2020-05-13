polygon : main.o polygon.o
	g++ main.o polygon.o -o polygon
polygon.o : polygon.hpp polygon.cpp
	g++ -c polygon.hpp polygon.cpp
main.o : polygon.hpp main.cpp
	g++ -c polygon.hpp main.cpp
clean :
	rm polygon main.o polygon.o
