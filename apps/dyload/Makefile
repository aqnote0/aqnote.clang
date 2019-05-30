#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

# Constant
MODULE_NAME 		= dyload
MODULE_INTRODUCE 	= 

# Depends
## Depend Module 
DEPEND_MODULE_LIST 		=

## Depend Path
DEPEND_NONSTD  		= SO1 SO2
DEPEND_SO1_HOME 	= ./depends/so1
DEPEND_SO1_LIB		= so1
DEPEND_SO2_HOME 	= ./depends/so2
DEPEND_SO2_LIB		= so2

## Depend System
DEPEND_STD 	= pthread

LDFLAGS += -ldl -Wl,-rpath=depends/so1/lib -Wl,-rpath=depends/so2/lib

# Compile
MODULE_LINK 		= cpp
# MODULE_BUILD 		= DEBUG
MODULE_OUTPUT 		= $(MODULE_NAME).app

include ../../mk/config.mk
include ${PROJECT_MAKEFILE_HOME}/global.mk