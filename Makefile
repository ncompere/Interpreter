export CC=g++
export CFLAGS=-W -Wall -std=c++11 -pedantic

main: main.o bloc.o struct_bloc.o parser.o tabulation.o
	$(CC) -o main main.o bloc.o struct_bloc.o parser.o tabulation.o $(CFLAGS)

main.o: main.cpp bloc.hpp struct_bloc.hpp parser.hpp tabulation.cpp
	$(CC) -o main.o -I. -c main.cpp $(CFLAGS)

bloc.o: bloc.cpp bloc.hpp
	$(CC) -o bloc.o -I. -c bloc.cpp $(CFLAGS)

struct_bloc.o: struct_bloc.cpp struct_bloc.hpp
	$(CC) -o struct_bloc.o -I. -c struct_bloc.cpp $(CFLAGS)

parser.o: parser.cpp parser.hpp
	$(CC) -o parser.o -I. -c parser.cpp $(CFLAGS)

tabulation.o: tabulation.cpp tabulation.hpp
	$(CC) -o tabulation.o -I. -c tabulation.cpp $(CFLAGS)

clean:
	rm -rf *.o *~ main
