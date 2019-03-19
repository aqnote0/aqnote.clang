
.PHONY: all
all: libso1.so

libso1.so: src/so1.o
	g++ -o libso1.so src/so1.o -shared

src/so1.o: src/so1.cpp src/so1.hpp
	g++ -o src/so1.o -c src/so1.cpp -fPIC

.PHONY: clean
clean:
	rm src/so1.o libso1.so
