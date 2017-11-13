output: main.o queue.o queuenode.o menu.o validate.o
	g++ -std=c++11 main.o queue.o queuenode.o menu.o validate.o -o circular

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

queue.o: queue.cpp queue.hpp
	g++ -c -std=c++11 queue.cpp

queuenode.o: queuenode.cpp queuenode.hpp
	g++ -c -std=c++11 queuenode.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o circular