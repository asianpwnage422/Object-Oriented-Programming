a.out:main.o polygon.o polynomial.o
	g++ -g main.o polygon.o polynomial.o
main.o:main.cpp polygon.hpp polynomial.hpp
	g++ -g -c main.cpp
polygon.o:polygon.cpp polygon.hpp
	g++ -g -c polygon.cpp
polynomial.o:polynomial.cpp polynomial.hpp
	g++ -g -c polynomial.cpp
clean:
	rm -f main.o polygon.o polynomial.o a.out
