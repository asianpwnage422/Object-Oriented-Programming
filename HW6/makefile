a.out : main.o student.o
	g++ main.o student.o 
main.o : main.cpp student.hpp
	g++ -c main.cpp student.hpp
student.o : student.cpp student.hpp
	g++ -c student.cpp student.hpp
clean :
	rm a.out main.o student.o 