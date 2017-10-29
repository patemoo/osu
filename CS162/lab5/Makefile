output: main.o recursive.o menu.o validate.o
	g++ -std=c++11 main.cpp recursive.cpp menu.o validate.o -o recurs 

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

recursive.o: recursive.cpp recursive.hpp
	g++ -c -std=c++11 recursive.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o recurs