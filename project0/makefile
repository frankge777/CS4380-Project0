Application: myUFls.o main.o
	g++ myUFls.o main.o -o main

main.o: main.cpp myUFls.h
	g++ -c main.cpp -o main.o

myUFls.o: myUFls.h myUFls.cpp
	g++ myUFls.cpp myUFls.h -c




clean:
	rm -f *.o main