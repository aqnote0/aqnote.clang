#     Title: common used Makefile
#    Author: "Peng Li"<aqnote@qq.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

## command
CC 		= gcc
CPP 	= g++
RM 		= rm -f

COMPILER = $(CC)
ifeq (cpp, ${MODULE_COMPILER})
	COMPILER = $(CPP)
endif

## targets
TARGETS 	:= $(MODULE_OUTPUT)

## get c source files
C_SOURCES = $(wildcard src/*.c)
OBJECTS = $(C_SOURCES:.c=.o)

## get cpp source file
CPP_SOURCES = $(wildcard src/*.cpp)
OBJECTS += $(CPP_SOURCES:.cpp=.o)

## add Source Depends
CFLAGS += $(foreach module, $(MODULE_DEPENDS), -I${PROJECT_MODULES_HOME}/${module}/include)
LDFLAGS +=$(foreach module, $(MODULE_DEPENDS), ${PROJECT_MODULES_HOME}/${module}/lib$(module).a)

## add Binary Depends
CFLAGS += -I./include
LDFLAGS += -L./lib

## add System Depends
### add Include
INCLUDE_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/include)
CFLAGS += $(foreach dir, $(INCLUDE_PATH), -I$(dir))

### add Library Path
LIBRARY_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/lib)
LDFLAGS += $(foreach dir, $(LIBRARY_PATH), -L$(dir))

### add Library File
LDFLAGS += $(foreach lib, $(LIBRARY_FILE), -l$(lib))

### add pkg-config
CFLAGS += $(foreach config, $(LIBRARY_PKG), $(shell pkg-config --cflags $(config))) 
LDFLAGS += $(foreach config, $(LIBRARY_PKG), $(shell pkg-config --libs $(config)))

BUILD = RELEASE
ifeq "DEBUG" "${MODULE_BUILD}"
	BUILD = DEBUG
endif

.PHONY: all
all: $(BUILD)

.PHONY: RELEASE
RELEASE: CFLAGS += -O2 -D NDEBUG -Wall -fwhole-program
RELEASE: $(TARGETS)

.PHONY: DEBUG
DEBUG: CFLAGS += -O0 -D_DEBUG -Wall -g -D_DEBUG=1
DEBUG: $(TARGETS)

$(MODULE_NAME).app: $(OBJECTS)
	$(COMPILER) -o $@ $(OBJECTS) $(LDFLAGS)

lib$(MODULE_NAME).so: $(OBJECTS)
	$(COMPILER) -o $@ $(OBJECTS) $(LDFLAGS) -shared

lib$(MODULE_NAME).a: $(OBJECTS)
	ar $(ARFLAGS) $@ $(OBJECTS)

## compile .c file
%.o : %.c
	${CC} -o $@ -c $< -std=c99 ${CFLAGS}
## compile .cpp file
%.o : %.cpp
	${CPP} -o $@ -c $< -std=c++11 ${CFLAGS}

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(TARGETS)

.PHONY: memcheck
memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(TARGETS) 

echo:
	echo [${PROJECT_MODULES_HOME}] > /dev/null