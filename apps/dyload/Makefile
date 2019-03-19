
#     Title: 
#    Author: "Peng Li"<aqnote@qq.com>
#     CDate: 20181210
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#
MODULE_NAME = gcc.assembly
MODULE_INTRODUCE = 
MODULE_DEPENDS = 
MODULE_BUILD = DEBUG

MODULE_COMPILER = cpp
MOUDLE_OUTPUT = main.app

LIBRARY_HOME := 
LIBRARY_FILE := 
LIBRARY_PKG  := 

include ../../constant.makefile
include ${PROJECT_HOME}/global.makefile

modules = so1 so2

.PHONY: all
all: main.app

.PHONY: $(modules)
$(modules):
	$(MAKE) -C $@ all

main.app: src/main.o $(modules)
	g++ -o main.app src/main.o -L./so1 -L./so2 -lso1 -lso2 -ldl -Wl,-rpath=./so1 -Wl,-rpath=./so2

src/main.o: src/main.cpp 
	g++ -o src/main.o -c src/main.cpp

.PHONY:clean
clean: cleanmodule
	rm src/main.o main.app

.PHONY: cleanmodule
cleanmodule:
	@for module in ${modules}; do \
		${MAKE} -C $$module clean; \
	done
