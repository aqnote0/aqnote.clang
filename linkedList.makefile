

# make -f linkedList.makefile

objects = linkedList.o linkedListMain.o

linkedListMain: $(objects) 
	gcc -o linkedListMain $(objects)

linkedListMain.o: linkedListMain.c linkedList.h 
	gcc -c linkedListMain.c

linkedList.o: linkedList.c linkedList.h
	gcc -c linkedList.c

clean: 
	rm -rf linkedList $(objects)
