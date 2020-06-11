test : main.o bigint.o
	g++ main.o bigint.o -o test
bigint.o : bigint.hpp bigint.cpp
	g++ -c bigint.hpp bigint.cpp
main.o : main.cpp bigint.hpp
	g++ -c bigint.hpp main.cpp
clean :
	rm test bigint.o main.o