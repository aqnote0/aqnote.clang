#     Title: common used Makefile
#    Author: "Peng Li"<aqnote@qq.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#


## defaug flag
APP_DEBUG = $(DEBUG)
APP_SOURCE := c

## 说明：由于/opt/aqnote不是ld标准路径库，因此在运行时需要设置链接库路径
## 在环境变量中添加 `export LD_LIBRARY_PATH=/opt/aqnote/lib`，这样才能运行
APP_LIBRARY_HOME := /opt/aqnote
APP_LIBRARY_FILES := json-c
APP_LIBRARY_PKG  := 

include ../../core.mk



