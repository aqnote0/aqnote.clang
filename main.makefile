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

SOURCE_COMPILER := $(CC)

## source file path
SOURCE_PATH 	:= .

## target exec file name
TARGET 		:= main.app

## get all source files
SRCS += $(wildcard $(SOURCE_PATH)/*.$(SOURCE_TYPE))
## all .0 based on all .c .cpp
OBJS = $(SRCS:.$(SOURCE_TYPE)=.o)

ifeq (1, ${SOURCE_DEBUG})
CFLAGS += -D_DEBUG -O0 -g -D_DEBUG=1
endif

## add Include and Library
INCLUDE_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/include)
CFLAGS += $(foreach dir, $(INCLUDE_PATH), -I$(dir))

LIBRARY_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/lib)
LDFLAGS += $(foreach dir, $(LIBRARY_PATH), -L$(dir))
LDFLAGS += $(foreach lib, $(LIBRARY_FILE), -l$(lib))

ifeq (cpp, ${SOURCE_TYPE})
SOURCE_COMPILER = $(CPP)
CFLAGS += -std=c++11
endif

## pkg-config
CFLAGS += $(foreach config, $(LIBRARY_PKG), $(shell pkg-config --cflags $(config))) 
LDFLAGS += $(foreach config, $(LIBRARY_PKG), $(shell pkg-config --libs $(config)))

all: build

build: 
	$(SOURCE_COMPILER) -c $(CFLAGS) $(SRCS)
	$(SOURCE_COMPILER) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(OBJS)
#$(RM) $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET)

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(TARGET) 