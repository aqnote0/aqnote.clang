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
MODULE_TARGET 		= $(MODULE_NAME).app

# Depends
## Depend Module 
DEPEND_MODULE_LIST 		=

## Depend Path
DEPEND_NONSTD_LIST  			= OPENCV FFMPEG
DEPEND_NONSTD_OPENCV_HOME 		= /opt/aqnote/opencv
DEPEND_NONSTD_OPENCV_LIB		= opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui
DEPEND_NONSTD_FFMPEG_HOME 		= /opt/aqnote/ffmpeg
DEPEND_NONSTD_FFMPEG_LIB		= avutil avformat avcodec swscale
DEPEND_NONSTD_FFMPEG_STATIC 	= 1

## Depend PKG-CONFIG
# DEPEND_PKG_CONFIG   = /opt/aqnote/opencv/lib/pkgconfig
# DEPEND_PKG			= opencv

## Depend System
DEPEND_STD 	= pthread


# Compile
MODULE_LINK 	= cpp
# MODULE_BUILD 		= DEBUG

include ../../mk/config.mk
include ${PROJECT_MAKEFILE_HOME}/global.mk
