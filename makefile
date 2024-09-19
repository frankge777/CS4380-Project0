Application: myUFls.o main.o
	g++ myUFls.o main.o -o main

myUFls.o: myUFls.cpp myUFls.h
	g++ -c myUFls.cpp -o myUFls.o

main.o: main.cpp myUFls.h
	g++ -c main.cpp -o main.o

clean:
	rm -f *.o main
