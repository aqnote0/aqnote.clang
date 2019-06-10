
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20181210
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#
include ../../mk/config.mk

###############################
# Module Info
###############################
MODULE_NAME 			= gcc.assembly
MODULE_INTRODUCE 		=
MODULE_TARGET 			= ${MODULE_NAME}.app

###############################
# Compile Options
###############################
MODULE_BUILD 		= DEBUG
MODULE_LINK 		= c
MODULE_TOOLCHAIN 	= x86_64-linux-gnu

include ${PROJECT_MAKEFILE_HOME}/global.mk

assemble:
	${CC} -S -o build/main.gas build/main.o

disassemble:
	${OBJDUMP} -s -d bin/${MODULE_TARGET} > bin/${MODULE_NAME}.txt