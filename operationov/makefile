test : main.o oov.o
	g++ -o test main.o oov.o
main.o : main.cpp oov.hpp
	g++ -c main.cpp oov.hpp
oov.o : oov.cpp oov.hpp
	g++ -c oov.cpp oov.hpp