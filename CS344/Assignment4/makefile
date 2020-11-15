line_processor: line_processor.o
	gcc --std=gnu99 -pthread -o line_processor line_processor.o

line_processor.o: line_processor.c
	gcc --std=gnu99 -pthread -c line_processor.c

clean: 
	rm line_processor.o line_processor