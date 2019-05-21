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
MODULE_DEPENDS_PROJ 		=

## Depend Path
MODULE_DEPENDS_NONSTD_LIST  = SO1 SO2
DEPEND_SO1_HOME 	= ./depends/so1
DEPEND_SO1_LIB		= so1
DEPEND_SO2_HOME 	= ./depends/so2
DEPEND_SO2_LIB		= so2

## Depend System
MODULE_DEPENDS_STD_LIST 	= pthread

LDFLAGS += -ldl -Wl,-rpath=depends/so1/lib -Wl,-rpath=depends/so2/lib

# Compile
MODULE_COMPILER 	= cpp
# MODULE_BUILD 		= DEBUG
MODULE_OUTPUT 		= $(MODULE_NAME).app

include ../../constant.makefile
include ${PROJECT_HOME}/global.makefile