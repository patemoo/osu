output: merge4.o merge4Time.o
	g++ merge4.o -o merge4
	g++ merge4Time.o -o merge4Time

merge4.o: merge4.cpp
	g++ -c -std=c++11 merge4.cpp

merge4Time.o: merge4Time.cpp
	g++ -c -std=c++11 merge4Time.cpp

clean:
	rm *.o merge4 merge4Time