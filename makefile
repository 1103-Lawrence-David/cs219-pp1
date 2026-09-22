execute: main.o operation.o
	g++ -o execute main.o operation.o

main.o: main.cpp operation.h
	g++ -c main.cpp

operation.o: operation.h operation.cpp
	g++ -c operation.cpp

make clean:
	rm *.o execute