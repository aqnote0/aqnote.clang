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
MODULE_NAME 		= algorithm.test
MODULE_INTRODUCE 	= 算法测试工程
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
DEPEND_MODULE_LIST 		= ALGORITHM
DEPEND_MODULE_ALGORITHM_HOME 	= ${PROJECT_MODULES_HOME}/aqnote_algorithm
DEPEND_MODULE_ALGORITHM_LIB 	= aqnote_algorithm
DEPEND_MODULE_ALGORITHM_STATIC	= 1

include ${PROJECT_MAKEFILE_HOME}/global.mk
