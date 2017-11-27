output: main.o buffer.o palindrome.o menu.o validate.o
	g++ -std=c++11 main.o buffer.o palindrome.o menu.o validate.o -o stl

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

buffer.o: buffer.cpp buffer.hpp
	g++ -c -std=c++11 buffer.cpp

palindrome.o: palindrome.cpp palindrome.hpp
	g++ -c -std=c++11 palindrome.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o stl