output: main.o university.o building.o person.o student.o instructor.o menu.o
	g++ -std=c++11 main.o university.o building.o person.o student.o instructor.o menu.o -o info

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

university.o: university.cpp university.hpp
	g++ -c -std=c++11 university.cpp

building.o: building.cpp building.hpp
	g++ -c -std=c++11 building.cpp

person.o: person.cpp person.hpp
	g++ -c -std=c++11 person.cpp

student.o: student.cpp student.hpp
	g++ -c -std=c++11 student.cpp

instructor.o: instructor.cpp instructor.hpp
	g++ -c -std=c++11 instructor.cpp

menu.o: menu.cpp menu.hpp
	g++ -c -std=c++11 menu.cpp

clean:
	rm *.o info