
output: matrixCalcMain.o readMatrix.o determinant.o
	g++ matrixCalcMain.o readMatrix.o determinant.o -o matrixCalc

matrixCalcMain.o: matrixCalcMain.cpp
	g++ -c -std=c++11 matrixCalcMain.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c -std=c++11 readMatrix.cpp

determinant.o: determinant.cpp determinant.hpp
	g++ -c -std=c++11 determinant.cpp

clean: 
	rm *.o matrixCalc