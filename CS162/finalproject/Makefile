output: main.o player.o state.o redstate.o bluestate.o swingstate.o menu.o
	g++ -std=c++11 main.o player.o state.o redstate.o bluestate.o swingstate.o menu.o -o trail

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

player.o: player.cpp player.hpp
	g++ -c -std=c++11 player.cpp

state.o: state.cpp state.hpp
	g++ -c -std=c++11 state.cpp

redstate.o: redstate.cpp redstate.hpp
	g++ -c -std=c++11 redstate.cpp

bluestate.o: bluestate.cpp bluestate.hpp
	g++ -c -std=c++11 bluestate.cpp

swingstate.o: swingstate.cpp swingstate.hpp
	g++ -c -std=c++11 swingstate.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

clean:
	rm *.o trail