#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

include ../../makefile.d/config.makefile

# Constant
MODULE_NAME 		= aqnote
MODULE_INTRODUCE 	= 模块DEMO

# Depends
## Depend Module 
DEPEND_MODULE 		=

## Depend Path
DEPEND_NONSTD  				= OPENCV FFMPEG
DEPEND_OPENCV_HOME 			= /opt/aqnote/opencv
DEPEND_OPENCV_LIB			= opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui

DEPEND_FFMPEG_HOME 			= /opt/aqnote/ffmpeg
DEPEND_FFMPEG_LIB			= avutil avformat avcodec swscale
DEPEND_FFMPEG_STATIC 		= 1

## Depend PKG-CONFIG
# DEPEND_PKG_CONFIG   	= /opt/aqnote/opencv/lib/pkgconfig
# DEPEND_PKG			= opencv

## Depend System
DEPEND_STD 	= pthread m

# Compile
MODULE_BUILD 		= DEBUG
MODULE_LINK 		= c
MODULE_TOOLCHAIN	= x86_64-linux-gnu
MODULE_OUTPUT 		= $(MODULE_NAME).app

include ${PROJECT_MAKEFILE_HOME}/global.makefile
