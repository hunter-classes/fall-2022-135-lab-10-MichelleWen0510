main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

funcs.o: funcs.cpp funcs.h time.h movie.h timeslot.h

main.o: main.cpp funcs.h time.h movie.h timeslot.h

tests.o: tests.cpp doctest.h funcs.h time.h movie.h timeslot.h

clean:
	rm -f main.o funcs.o tests.o
