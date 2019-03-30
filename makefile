student.o: include/student.hpp src/student.cpp
	g++ -c src/student.cpp

main.o: src/main.cpp include/student.hpp
	g++ -c src/main.cpp

file_functions.o: include/file_functions.hpp include/student.hpp src/file_functions.cpp
	g++ -c src/file_functions.cpp

main: main.o student.o file_functions.o
	g++ main.o student.o file_functions.o -o main

run: main
	./main

.PHONY: run
