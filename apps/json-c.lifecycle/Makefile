
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20190325
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

# Constant
MODULE_NAME 		= json-c.lifecycle
MODULE_INTRODUCE 	=

# Depends
## 说明：由于/opt/aqnote不是ld标准路径库，因此在运行时需要设置链接库路径
## 在环境变量中添加 `export LD_LIBRARY_PATH=/opt/aqnote/lib`，这样才能运行
DEPEND_MODULE 		=
DEPEND_PKG			=
MODULE_DEPENDS_NONSTD_PATH 	= /opt/aqnote/json-c
MODULE_DEPENDS_NONSTD_FILE	= json-c

# Compile
MODULE_LINK 	=
MODULE_BUILD 		= DEBUG
MODULE_OUTPUT 		= $(MODULE_NAME).app

include ../../makefile.d/config.makefile
include ${PROJECT_MAKEFILE_HOME}/global.makefile


