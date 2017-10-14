
output: main.o count.o output.o
	g++ -std=c++11 main.o count.o output.o -o inout

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

count.o: count.cpp count.hpp
	g++ -c -std=c++11 count.cpp

output.o: output.cpp output.hpp
	g++ -c -std=c++11 output.cpp

clean: 
	rm *.o inout