
output: main.o game.o die.o loadedDie.o menu.o validate.o
	g++ -std=c++11 main.o game.o die.o loadedDie.o menu.o validate.o -o war

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

game.o: game.cpp game.hpp
	g++ -c -std=c++11 game.cpp

die.o: die.cpp die.hpp
	g++ -c -std=c++11 die.cpp

loadedDie.o: loadedDie.cpp loadedDie.hpp
	g++ -c -std=c++11 loadedDie.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o war