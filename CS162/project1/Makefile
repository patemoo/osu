
output: main.o menu.o ant.o validate.o
	g++ main.o menu.o ant.o validate.o -o langton

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

ant.o: ant.cpp ant.hpp
	g++ -c -std=c++11 ant.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o langton