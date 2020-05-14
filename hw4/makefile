poly : main.o polygon.o polynomial.o
	g++ main.o polygon.o polynomial.o -o poly
polygon.o : polygon.hpp polygon.cpp
	g++ -c polygon.hpp polygon.cpp
polynomial.o : polynomial.hpp polynomial.cpp
	g++ -c polynomial.hpp polynomial.cpp
main.o : polygon.hpp polynomial.hpp main.cpp
	g++ -c polygon.hpp polynomial.hpp main.cpp
clean :
	rm poly main.o polygon.o polynomial.o 
