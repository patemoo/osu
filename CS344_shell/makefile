smallsh: smallsh.o userInput.o
	gcc --std=gnu99 -o smallsh smallsh.o userInput.o

smallsh.o: smallsh.c userInput.h
	gcc --std=gnu99 -c smallsh.c

userInput.o: userInput.c userInput.h
	gcc --std=gnu99 -c userInput.c

clean:
	rm smallsh.o smallsh userInput.o
