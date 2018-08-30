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
RM 		= rm -rf

## defaug flag
DEBUG_ENABLE = 0

## source file path
SRC_PATH 	:= .

## target exec file name
TARGET 		:= main

## get all source files
SRCS += $(wildcard $(SRC_PATH)/*.c)
## all .0 based on all .c
OBJS := $(SRCS:.c=.o)

## add Include and Library
LIBRARY_HOME := 
LIBRARYS := 
INCLUDE_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/include)
LIBRARY_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/lib)

ifeq (1, ${DEBUG_ENABLE})
CFLAGS += -D_DEBUG -O0 -g -D_DEBUG=1
endif

## add include_path
CFLAGS += $(foreach dir, $(INCLUDE_PATH), -I$(dir))
## add library_path
LDFLAGS += $(foreach dir, $(LIBRARY_PATH), -L$(dir))
## add library file
LDFLAGS += $(foreach lib, $(LIBRARYS), -l$(lib))

## pkg-config
#CFLAGS += `pkg-config --cflags xxx`
#LDFLAGS += `pkg-config --libs xxx`


all: assembly

assembly:
	$(CC) -S $(CFLAGS) $(SRCS)

build: 
	$(CC) -c $(CFLAGS) $(SRCS)
	$(CC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(OBJS)
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET)

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(TARGET) 




