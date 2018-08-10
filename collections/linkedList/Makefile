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

INCLUDE_PATH = -I. -I./include
LIBRARY_PATH = -L. -L./libs
LIBS = 

CFLAGS = $(INCLUDE_PATH)
LDFLAGS = $(LIBRARY_PATH) $(LIBS)


TARGET = main
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)  # expands to list of object files

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJS) 
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)


clean: 
	rm -rf $(OBJS)

distclean: 
	rm -rf $(OBJS) $(TARGET)