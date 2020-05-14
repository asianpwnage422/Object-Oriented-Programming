diamond : main.o diamond.o
	g++ diamond.o main.o -o diamond
main.o:main.o diamond.h
	g++ -c main.cpp diamond.h
diamond.o:diamond.cpp diamond.h
	g++ -c diamond.cpp diamond.h
clean:
	rm diamond diamond.o main.o 
