student.o: include/student.hpp src/student.cpp
	g++ -c src/student.cpp

file_functions.o: include/file_functions.hpp include/student.hpp src/file_functions.cpp
	g++ -c src/file_functions.cpp


database_functions.o: include/student.hpp include/database_functions.hpp include/file_functions.hpp src/database_functions.cpp
	g++ -c src/database_functions.cpp

main.o: src/main.cpp include/database_functions.hpp include/file_functions.hpp
	g++ -c src/main.cpp

main: main.o student.o file_functions.o database_functions.o
	g++ main.o student.o file_functions.o database_functions.o -o main

run: main
	./main

.PHONY: run
