output: main.o search.o binarysearch.o bubblesort.o validate.o
	g++ -std=c++11 main.o search.o binarysearch.o bubblesort.o validate.o -o sort

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

search.o: search.cpp search.hpp
	g++ -c -std=c++11 search.cpp

binarysearch.o: binarysearch.cpp binarysearch.hpp
	g++ -c -std=c++11 binarysearch.cpp

bubblesort.o: bubblesort.cpp bubblesort.hpp
	g++ -c -std=c++11 bubblesort.cpp

validate.o: validate.cpp validate.hpp
	g++ -c -std=c++11 validate.cpp

clean:
	rm *.o sort