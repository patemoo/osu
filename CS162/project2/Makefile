
output: main.o player.o zoo.o animal.o tiger.o penguin.o turtle.o menu.o
	g++ -std=c++11 main.o player.o zoo.o animal.o tiger.o penguin.o turtle.o menu.o -o zoo

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

player.o: player.cpp player.hpp
	g++ -c -std=c++11 player.cpp

zoo.o: zoo.cpp zoo.hpp
	g++ -c -std=c++11 zoo.cpp

animal.o: animal.cpp animal.hpp
	g++ -c -std=c++11 animal.cpp

tiger.o: tiger.cpp tiger.hpp
	g++ -c -std=c++11 tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	g++ -c -std=c++11 penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	g++ -c -std=c++11 turtle.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

clean:
	rm *.o zoo