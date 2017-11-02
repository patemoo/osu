output: main.o menu.o
	g++ -std=c++11 main.o menu.o -o linked

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

clean:
	rm *.o