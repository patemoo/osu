output: lastToStart.o activity.o
	g++ lastToStart.o activity.o -o lastToStart

lastToStart.o: lastToStart.cpp
	g++ -c -std=c++11 lastToStart.cpp

activity.o: activity.cpp activity.hpp
	g++ -c -std=c++11 activity.cpp

clean: 
	rm *.o lastToStart