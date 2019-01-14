
output: insertsort.o mergesort.o inserttime.o mergetime.o
	g++ insertsort.o -o insertsort
	g++ mergesort.o -o mergesort
	g++ inserttime.o -o insertTime
	g++ mergetime.o -o mergeTime

insertsort.o: insertsort.cpp
    g++ -c -std=c++11 insertsort.cpp

mergesort.o: mergesort.cpp
    g++ -c -std=c++11 mergesort.cpp

inserttime.o: inserttime.cpp
	g++ -c -std=c++11 inserttime.cpp

mergetime.o: mergetime.cpp
	g++ -c -std=c++11 mergetime.cpp

clean:
	rm *.o mergesort insertsort