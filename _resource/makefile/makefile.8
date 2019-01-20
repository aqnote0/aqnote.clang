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

## source file path
SRC_PATH 	:= .

## target exec file name
TARGET 		:= main

## get all source files
SRCS += $(wildcard $(SRC_PATH)/*.c)
## all .0 based on all .c
OBJS := $(SRCS:.c=.o)

## defaug flag
AQN_APP_DEBUG = $(APP_DEBUG)

## add Include and Library
AQN_APP_HOME := $(APP_HOME)
AQN_APP_LIBS := $(APP_LIBS)
INCLUDE_PATH += $(foreach dir, $(AQN_APP_HOME), $(dir)/include)
LIBRARY_PATH += $(foreach dir, $(AQN_APP_HOME), $(dir)/lib)

ifeq (1, ${AQN_APP_DEBUG})
CFLAGS += -D_DEBUG -O0 -g -D_DEBUG=1
endif

CFLAGS += $(foreach dir, $(INCLUDE_PATH), -I$(dir))
LDFLAGS += $(foreach dir, $(LIBRARY_PATH), -L$(dir))
LDFLAGS += $(foreach lib, $(AQN_APP_LIBS), -l$(lib))

###CFLAGS += -std=c++11

## pkg-config
AQN_APP_PKG := $(APP_PKG)
CFLAGS += $(foreach config, $(AQN_APP_PKG), $(shell pkg-config --cflags $(config))) 
LDFLAGS += $(foreach config, $(AQN_APP_PKG), $(shell pkg-config --libs $(config)))

all: build

build: 
	$(CC) -c $(CFLAGS) $(SRCS)
	$(CC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) $(OBJS)
	$(RM) $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET)

memcheck:
	valgrind --tool=memcheck --leak-check=full ./$(TARGET) 
