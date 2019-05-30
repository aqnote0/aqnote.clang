#     Title: Toolchain
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20190527
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

###############################
## Input Variable
###############################
AQNOTE_LINK			= ${MODULE_LINK}
AQNOTE_TOOLCHAIN	= ${MODULE_TOOLCHAIN}

CC 				= ${AQNOTE_TOOLCHAIN}-gcc
CPP 			= ${AQNOTE_TOOLCHAIN}-g++
LINK 			= ${AQNOTE_TOOLCHAIN}-ld
AR  			= ${AQNOTE_TOOLCHAIN}-ar
NM  			= ${AQNOTE_TOOLCHAIN}-nm
RANLIB			= ${AQNOTE_TOOLCHAIN}-ranlib
STRIP 			= ${AQNOTE_TOOLCHAIN}-strip
STRINGS			= ${AQNOTE_TOOLCHAIN}-strings
SIZE 			= ${AQNOTE_TOOLCHAIN}-size
OBJDUMP			= ${AQNOTE_TOOLCHAIN}-objdump
OBJCOPY			= ${AQNOTE_TOOLCHAIN}-objcopy
PKG-CONFIG 		= ${AQNOTE_TOOLCHAIN}-pkg-config

ifeq "cpp" "${AQNOTE_LINK}"
	LINK = $(CPP)
endif
ifeq "c" "${AQNOTE_LINK}"
	LINK = $(CC)
endif