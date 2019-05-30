#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20181210
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

###############################
## Input Variable
###############################

ifeq "" "${PROJECT_HOME}"
	PROJECT_HOME 			= ../..
	PROJECT_BUILD_HOME 		= ${PROJECT_HOME}/build
	PROJECT_APPS_HOME 		= ${PROJECT_HOME}/apps
	PROJECT_DOCS_HOME 		= ${PROJECT_HOME}/docs
	PROJECT_MODULES_HOME 	= ${PROJECT_HOME}/modules
	PROJECT_3RDPARTY_HOME	= ${PROJECT_HOME}/3rdparty
	PROJECT_MAKEFILE_HOME	= ${PROJECT_HOME}/mk
endif