exe: main.o 
	g++ -o exe.out main.o $(shell pkg-config --cflags --libs opencv)

main.o: ../main.cpp 
	g++ -c ../main.cpp -Wall -std=c++11

clean: ; rm -f *.o 