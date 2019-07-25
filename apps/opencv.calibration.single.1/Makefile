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
MODULE_NAME 		= opencv.affine
MODULE_INTRODUCE 	= opencv仿射变换例子
MODULE_TARGET 		= $(MODULE_NAME).app

###############################
# Compile Options
###############################
MODULE_BUILD 		= DEBUG
MODULE_LINK 		= cpp
MODULE_TOOLCHAIN	= x86_64-linux-gnu

# Depends
###############################
## Depend Module 
###############################


###############################
## Depend 3rdParty
###############################


###############################
## Depend NONSTD
###############################
DEPEND_NONSTD_LIST  				= OPENCV #FFMPEG

DEPEND_NONSTD_OPENCV_HOME 			= /opt/aqnote/opencv
DEPEND_NONSTD_OPENCV_LIB			= opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui opencv_calib3d

DEPEND_NONSTD_FFMPEG_HOME 			= /opt/aqnote/ffmpeg
DEPEND_NONSTD_FFMPEG_LIB			= avutil avformat avcodec swscale
DEPEND_NONSTD_FFMPEG_STATIC 		= 1

###############################
## Depend PKG-CONFIG
###############################

###############################
## Depend STD
###############################
DEPEND_STD 	= pthread m

include ${PROJECT_MAKEFILE_HOME}/global.mk
