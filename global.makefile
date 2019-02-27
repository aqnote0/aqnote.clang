#     Title: common used Makefile
#    Author: "Peng Li"<aqnote@qq.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

## variable
#SOURCE_DEBUG
#APP_COMPILER
#LIBRARY_PKG
#LIBRARY_HOME
#SOURCE_TYPE

## command
CC 		= gcc
CPP 	= g++
RM 		= rm -f

## target exec file name
TARGET 		:= $(MODULE_NAME)${MODULE_TYPE}

## get all source files
C_SOURCES = $(wildcard src/*.c)
CPP_SOURCES = $(wildcard src/*.cpp)
## all .0 based on all .c .cpp
OBJECTS = $(C_SOURCES:.c=.o) $(CPP_SOURCES:.cpp=.o)

## add Project Dependency Modules
CFLAGS += $(foreach module, $(MODULE_DEPENDS), -I${PROJECT_MODULES_HOME}/${module}/include)
LDFLAGS +=$(foreach module, $(MODULE_DEPENDS), ${PROJECT_MODULES_HOME}/${module}/lib$(module).a)

## add Include and Library
INCLUDE_PATH += ./include $(foreach dir, $(LIBRARY_HOME), $(dir)/include)
LIBRARY_PATH += ./lib $(foreach dir, $(LIBRARY_HOME), $(dir)/lib)
CFLAGS += $(foreach dir, $(INCLUDE_PATH), -I$(dir))
LDFLAGS += $(foreach dir, $(LIBRARY_PATH), -L$(dir)) $(foreach lib, $(LIBRARY_FILE), -l$(lib))

## pkg-config
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
RELEASE: $(TARGET)

.PHONY: DEBUG
DEBUG: CFLAGS += -O0 -D_DEBUG -Wall -g -D_DEBUG=1
DEBUG: $(TARGET)

$(MODULE_NAME).app: $(OBJECTS)
	$(CPP) -o $@ $(OBJECTS) $(LDFLAGS)

$(MODULE_NAME).so: $(OBJECTS)
	$(CPP) -o $(TARGET_SO) $(OBJECTS) $(LDFLAGS) -shared

$(MODULE_NAME).a: $(OBJECTS)
	ar $(ARFLAGS) $@ $(OBJECTS)

## compile .c .cpp file
%.o : %.c
	${CC} -o $@ -c $< -std=c99 ${CFLAGS}
%.o : %.cpp
	${CPP} -o $@ -c $< -std=c++11 ${CFLAGS}

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(TARGET)

.PHONY: memcheck
memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(TARGET) 

echo:
	echo [${PROJECT_MODULES_HOME}] > /dev/null