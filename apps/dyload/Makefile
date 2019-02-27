main.app: src/main.o
	g++ -o main.app src/main.o -L./so1 -L./so2 -lso1 -lso2 -ldl -Wl,-rpath=./so1 -Wl,-rpath=./so2

src/main.o: src/main.cpp 
	g++ -o src/main.o -c src/main.cpp

.PHONY:clean
clean:
	rm src/main.o main.app
