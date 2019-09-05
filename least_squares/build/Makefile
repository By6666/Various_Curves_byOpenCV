exe: test.o least_squares.o
	g++ -o exe.out test.o least_squares.o $(shell pkg-config --cflags --libs opencv)

test.o: ../test.cpp 
	g++ -c ../test.cpp -Wall -std=c++11

least_squares.o: ../least_squares/least_squares.cpp
	g++ -c ../least_squares/least_squares.cpp -Wall

clean: ; rm -f *.o 
