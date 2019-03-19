#
#     Title: 
#    Author: "Peng Li"<aqnote@qq.com>
#     CDate: 20181210
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

# Constant
MODULE_NAME = dyload
MODULE_INTRODUCE =

# Depends
MODULE_DEPENDS_PROJ 		=
MODULE_DEPENDS_PKG			=
MODULE_DEPENDS_NONSTD_PATH 	=
MODULE_DEPENDS_NONSTD_FILE	=

# Compile
MODULE_COMPILER = cpp
MODULE_BUILD = DEBUG
MODULE_OUTPUT = $(MODULE_NAME).app

modules = so1 so2

COMPILER = g++

.PHONY: all
all: $(MODULE_OUTPUT)

.PHONY: $(modules)
$(modules):
	$(MAKE) -C $@ all

$(MODULE_OUTPUT): src/main.o $(modules)
	$(COMPILER) -o $@ src/main.o -L./so1 -lso1 -L./so2 -lso2 -ldl -Wl,-rpath=./so1 -Wl,-rpath=./so2

## compile .cpp file
%.o : %.cpp
	${COMPILER} -o $@ -c $< -std=c++11 ${CFLAGS}

.PHONY:clean
clean: cleanmodule
	rm src/main.o main.app

.PHONY: cleanmodule
cleanmodule:
	@for module in ${modules}; do \
		${MAKE} -C $$module clean; \
	done
