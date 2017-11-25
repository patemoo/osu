output: main.o lineup.o lineupnode.o character.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o menu.o validate.o
	g++ -std=c++11 main.o lineup.o lineupnode.o character.o vampire.o barbarian.o bluemen.o medusa.o harrypotter.o menu.o validate.o -o combat

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

lineup.o: lineup.cpp lineup.hpp
	g++ -c -std=c++11 lineup.cpp

lineupnode.o: lineupnode.cpp lineupnode.hpp
	g++ -c -std=c++11 lineupnode.cpp

character.o: character.cpp character.hpp
	g++ -c -std=c++11 character.cpp

vampire.o: vampire.cpp vampire.hpp
	g++ -c -std=c++11 vampire.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	g++ -c -std=c++11 barbarian.cpp

bluemen.o: bluemen.cpp bluemen.hpp
	g++ -c -std=c++11 bluemen.cpp

medusa.o: medusa.cpp medusa.hpp
	g++ -c -std=c++11 medusa.cpp

harrypotter.o: harrypotter.cpp harrypotter.hpp
	g++ -c -std=c++11 harrypotter.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o combat