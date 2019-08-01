INCLUDE_DIR := include
SOURCE_DIR := src
BUILD_DIR := build
BINARY_DIR := bin

.PHONY: all
all: libso2.so

libso2.so: $(BUILD_DIR)/so2.o
	g++ -o $@ $^ -shared 
	@mkdir -p lib
	@mv $@ lib

$(BUILD_DIR)/so2.o: $(SOURCE_DIR)/so2.cpp $(SOURCE_DIR)/so2.hpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ -c $< -fPIC

.PHONY:clean
clean:
	@rm -rf $(BUILD_DIR) $(BINARY_DIR)
