a.out : main2.o student.o
	g++ main2.o student.o 
main2.o : main2.cpp student.hpp
	g++ -c main2.cpp student.hpp
student.o : student.cpp student.hpp
	g++ -c student.cpp student.hpp
clean :
	rm a.out main2.o student.o 