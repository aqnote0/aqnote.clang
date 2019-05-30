#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20181210
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

include ../../makefile.d/config.makefile

# Constant
MODULE_NAME 		= multimodule
MODULE_INTRODUCE 	=

# Depends
#DEPEND_MODULE 		= moduleA moduleB
DEPEND_NONSTD 		= moduleA moduleB
DEPEND_moduleA_HOME = $(PROJECT_MODULES_HOME)/moduleA
DEPEND_moduleA_LIB	= moduleA

DEPEND_moduleB_HOME = $(PROJECT_MODULES_HOME)/moduleB
DEPEND_moduleB_LIB	= moduleB


DEPEND_PKG			=

# Compile
MODULE_LINK 		= cpp
# MODULE_BUILD 		= DEBUG
MODULE_OUTPUT 		= $(MODULE_NAME).app


include ${PROJECT_MAKEFILE_HOME}/global.makefile
