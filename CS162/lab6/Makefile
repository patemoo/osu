output: main.o linkedList.o node.o menu.o validate.o
	g++ -std=c++11 main.o linkedList.o node.o menu.o validate.o -o linked

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

linkedList.o: linkedList.cpp linkedList.hpp
	g++ -c -std=c++11 linkedList.cpp

node.o: node.cpp node.hpp
	g++ -c -std=c++11 node.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o linked