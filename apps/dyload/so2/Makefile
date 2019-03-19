.PHONY: all
all: libso2.so

libso2.so: src/so2.o
	g++ -o libso2.so src/so2.o -shared 

src/so2.o: src/so2.cpp src/so2.hpp
	g++ -o src/so2.o -c src/so2.cpp -fPIC 

.PHONY:clean
clean:
	rm src/so2.o libso2.so
