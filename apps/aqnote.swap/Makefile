#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

# Constant
MODULE_NAME 		= aqnote.swap
MODULE_INTRODUCE 	= swap函数的几种实现

# Depends
## Depend Module 
MODULE_DEPENDS_PROJ 		=

## Depend Path
MODULE_DEPENDS_NONSTD_LIST  = OPENCV FFMPEG
DEPEND_OPENCV_HOME 			= /opt/aqnote/opencv
DEPEND_OPENCV_LIB			= opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui

DEPEND_FFMPEG_HOME 			= /opt/aqnote/ffmpeg
DEPEND_FFMPEG_LIB			= avutil avformat avcodec swscale
DEPEND_FFMPEG_STATIC 		= 1

## Depend PKG-CONFIG
# MODULE_DEPENDS_PKG_CONFIG   = /opt/aqnote/opencv/lib/pkgconfig
# MODULE_DEPENDS_PKG			= opencv

## Depend System
MODULE_DEPENDS_STD_LIST 	= pthread


# Compile
MODULE_COMPILER 	= cpp
# MODULE_BUILD 		= DEBUG
MODULE_OUTPUT 		= $(MODULE_NAME).app

include ../../constant.makefile
include ${PROJECT_HOME}/global.makefile
