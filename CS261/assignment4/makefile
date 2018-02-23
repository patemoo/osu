all: prog1 prog2

prog1: dynArray.o main.o toDoList.o
	gcc -g -Wall -std=c99 -o prog1 dynArray.o toDoList.o main.o
	
prog2: dynArray.o main2.o toDoList.o
	gcc -g -Wall -std=c99 -o prog2 dynArray.o toDoList.o main2.o
	
main.o: main.c dynArray.h type.h toDoList.h
	gcc -g -Wall -std=c99 -c main.c
	
main2.o: main2.c dynArray.h type.h toDoList.h
	gcc -g -Wall -std=c99 -c main2.c
	
dynArray.o: dynArray.c dynArray.h
	gcc -g -Wall -std=c99 -c dynArray.c
	
toDoList.o: toDoList.c toDoList.h
	gcc -g -Wall -std=c99 -c toDoList.c

clean:	
	rm dynArray.o
	rm toDoList.o
	rm main.o
	rm main2.o
	rm prog1
	rm prog2
