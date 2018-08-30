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
DEBUG_ENABLE = 1

## source file path
SRC_PATH 	:= .

## target exec file name
TARGET 		:= main

## get all source files
SRCS += $(wildcard $(SRC_PATH)/*.c)
## all .0 based on all .c
OBJS := $(SRCS:.c=.o)

## add Include and Library
LIBRARY_HOME := /opt/aqnote
LIBRARYS := json-c
INCLUDE_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/include)
LIBRARY_PATH += $(foreach dir, $(LIBRARY_HOME), $(dir)/lib)

ifeq (1, ${DEBUG_ENABLE})
CFLAGS += -D_DEBUG -O0 -g -D_DEBUG=1
endif

CFLAGS += $(foreach dir, $(INCLUDE_PATH), -I$(dir))
LDFLAGS += $(foreach dir, $(LIBRARY_PATH), -L$(dir))
LDFLAGS += $(foreach lib, $(LIBRARYS), -l$(lib))

## pkg-config
#CFLAGS += `pkg-config --cflags xxx`
#LDFLAGS += `pkg-config --libs xxx`


all: build

build: 
	$(CC) -c $(CFLAGS) $(SRCS)
	$(CC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(OBJS)
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET)

memcheck:
	valgrind --tool=memcheck ./$(TARGET) 
