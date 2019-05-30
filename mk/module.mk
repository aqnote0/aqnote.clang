#     Title: Module Structure
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20190527
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

###############################
## MODULE STRUCTURE
###############################
export INCLUDE_DIR		:= include
export SOURCE_DIR		:= src
export LIBRARY_DIR		:= lib
export BINARY_DIR 		:= bin
export BUILD_DIR 		:= build
# export DEPENDS_DIR 		:= depends
export DIST_DIR			:= dist


###############################
## INCLUDE CODE
###############################
### add Current Module Include
CFLAGS += -Iinclude

###############################
## SOURCE CODE
###############################
## get c source files
C_SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(C_SOURCES:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)

## get cpp source file
CPP_SOURCES = $(wildcard $(SOURCE_DIR)/*.cpp)
OBJECTS += $(CPP_SOURCES:$(SOURCE_DIR)/%.cpp=$(BUILD_DIR)/%.o)