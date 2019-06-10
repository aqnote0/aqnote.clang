#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

include ../../mk/config.mk

###############################
# Module Info
###############################
MODULE_NAME 		= aqnote
MODULE_INTRODUCE 	= 模块DEMO
MODULE_TARGET 		= $(MODULE_NAME).app

###############################
# Compile Options
###############################
MODULE_BUILD 		= DEBUG
MODULE_LINK 		= c
MODULE_TOOLCHAIN	= x86_64-linux-gnu

# Depends
###############################
## Depend Module 
###############################
DEPEND_MODULE_LIST 			= AQNOTE_A AQNOTE_B

DEPEND_MODULE_AQNOTE_A_HOME = $(PROJECT_MODULES_HOME)/aqnote_a
DEPEND_MODULE_AQNOTE_A_LIB	= aqnote_a

DEPEND_MODULE_AQNOTE_B_HOME = $(PROJECT_MODULES_HOME)/aqnote_b
DEPEND_MODULE_AQNOTE_B_LIB	= aqnote_b

###############################
## Depend 3rdParty
###############################
DEPEND_THIRD_LIST	=

###############################
## Depend NONSTD
###############################
DEPEND_NONSTD_LIST  				= OPENCV FFMPEG

DEPEND_NONSTD_OPENCV_HOME 			= /opt/aqnote/opencv
DEPEND_NONSTD_OPENCV_LIB			= opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui

DEPEND_NONSTD_FFMPEG_HOME 			= /opt/aqnote/ffmpeg
DEPEND_NONSTD_FFMPEG_LIB			= avutil avformat avcodec swscale
DEPEND_NONSTD_FFMPEG_STATIC 		= 1

###############################
## Depend PKG-CONFIG
###############################
# DEPEND_PKG_CONFIG   	= /opt/aqnote/opencv/lib/pkgconfig
# DEPEND_PKG			= opencv

###############################
## Depend STD
###############################
DEPEND_STD 	= pthread m

include ${PROJECT_MAKEFILE_HOME}/global.mk
