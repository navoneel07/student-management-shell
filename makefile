display.o: include/display.hpp src/display.cpp
	g++ -c -std=c++11 -pedantic-errors src/display.cpp

student.o: include/student.hpp src/student.cpp
	g++ -c -std=c++11 -pedantic-errors src/student.cpp

file_functions.o: include/file_functions.hpp include/student.hpp src/file_functions.cpp
	g++ -c -std=c++11 -pedantic-errors src/file_functions.cpp

qlang.o: include/file_functions.hpp include/student.hpp include/qlang.hpp src/qlang.cpp
	g++ -c -std=c++11 -pedantic-errors src/qlang.cpp

database_functions.o: include/qlang.hpp include/student.hpp include/database_functions.hpp include/file_functions.hpp src/database_functions.cpp
	g++ -c -std=c++11 -pedantic-errors src/database_functions.cpp

main.o: src/main.cpp include/database_functions.hpp include/file_functions.hpp
	g++ -c -std=c++11 -pedantic-errors src/main.cpp

main: main.o display.o student.o file_functions.o database_functions.o qlang.o display.o
	g++ -std=c++11 -pedantic-errors main.o student.o file_functions.o database_functions.o qlang.o display.o -o main

run: main
	./main

.PHONY: run
