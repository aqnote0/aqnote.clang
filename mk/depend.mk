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

## add static and dynamic
# -L/usr/lib64/mysql \
 -Wl,-Bstatic -lmysqlclient \
 -Wl,-Bdynamic -lz -lcrypt -lnsl -lm \
 -L/usr/lib64 -lssl -lcrypto

LINK_STATIC_OPT = -Wl,-Bstatic
LINK_DYNAMIC_OPT = -Wl,-Bdynamic
LINK_DYNAMIC_OPT2 = -Wl,-rpath='$$ORIGIN/../lib'
COMMAND_LINK = $(foreach lib, $1,$(if $2,$2 -l$(lib),-l$(lib)))

###############################
### add Module Source Depends
### 模块依赖，需要打包到最终分发包
###############################
ifneq "" "$(DEPEND_MODULE_LIST)"
	CFLAGS += $(foreach module, $(DEPEND_MODULE_LIST), -I$(DEPEND_MODULE_$(module)_HOME)/include)
	LDFLAGS += $(foreach module, $(DEPEND_MODULE_LIST), \
					-L$(DEPEND_MODULE_$(module)_HOME)/lib \
					$(if $(DEPEND_MODULE_$(module)_STATIC), \
						$(call COMMAND_LINK, $(DEPEND_MODULE_$(module)_LIB), $(LINK_STATIC_OPT)), \
						$(call COMMAND_LINK, $(DEPEND_MODULE_$(module)_LIB), $(LINK_DYNAMIC_OPT2)) \
					) \
					$(if $(DEPEND_MODULE_$(module)_STATIC), $(LINK_DYNAMIC_OPT)) \
				)
endif

###############################
### add Third Party Depends
### 3rdparty依赖，需要打包到最终分发包
###############################
ifneq "" "${DEPEND_THIRD_LIST}"
	CFLAGS += $(foreach module, $(DEPEND_THIRD_LIST), -I$(DEPEND_THIRD_$(module)_HOME)/include)
	LDFLAGS += $(foreach module, $(DEPEND_THIRD_LIST), 							\
					-L$(DEPEND_THIRD_$(module)_HOME)/lib											\
					$(if $(DEPEND_THIRD_$(module)_STATIC), 											\
						$(call COMMAND_LINK, $(DEPEND_THIRD_$(module)_LIB), $(LINK_STATIC_OPT)), 	\
						$(call COMMAND_LINK, $(DEPEND_THIRD_$(module)_LIB), $(LINK_DYNAMIC_OPT2)) 	\
					)																				\
					$(if $(DEPEND_THIRD_$(module)_STATIC), $(LINK_DYNAMIC_OPT))						\
				)
endif

# # ### add Module Binary Depends
# # DEPENDS = $(shell ls depends 2>/dev/null)
# # ifneq "" "$(DEPENDS)"
# # 	CFLAGS += $(foreach module, $(DEPENDS), -I$(DEPENDS_DIR)/${module}/include)
# # 	LDFLAGS += $(foreach module, $(DEPENDS), $(DEPENDS_DIR)/${module}/lib/lib$(module).a)
# # endif
# DEPENDS = $(shell ls depends 2>/dev/null)
# ifneq "" "$(DEPENDS)"
# 	MODULE_DEPS = $(foreach module, $(DEPENDS), $(DEPENDS_DIR)/${module})
# endif

###############################
### add System Dir Depends
### 系统非标准依赖，不需要打包进最终分发包，但是需要环境准备好
###############################
ifneq "" "$(DEPEND_NONSTD_LIST)"
	CFLAGS += $(foreach module, $(DEPEND_NONSTD_LIST), -I$(DEPEND_NONSTD_$(module)_HOME)/include)
	LDFLAGS += $(foreach module, $(DEPEND_NONSTD_LIST), 											\
					-L$(DEPEND_NONSTD_$(module)_HOME)/lib											\
					$(if $(DEPEND_NONSTD_$(module)_STATIC), 										\
						$(call COMMAND_LINK, $(DEPEND_NONSTD_$(module)_LIB), $(LINK_STATIC_OPT)), 	\
						$(call COMMAND_LINK, $(DEPEND_NONSTD_$(module)_LIB)) 						\
					)																				\
					$(if $(DEPEND_NONSTD_$(module)_STATIC), $(LINK_DYNAMIC_OPT))					\
				)
endif

###############################
### add System STD Depends
### 系统标准依赖，不需要打包进最终分发包，但是需要环境准备好
###############################
ifneq "" "$(DEPEND_STD)"
	LDFLAGS += $(foreach lib, $(DEPEND_STD), -l${lib})
endif

###############################
### add pkg-config
### pkg-config方式依赖，不需要打包进最终分发包，但需要准备好环境
###############################
# export PKG_CONFIG_PATH=${DEPEND_PKG_CONFIG}
ifneq "" "$(DEPEND_PKG)"
	CFLAGS += $(foreach config, $(DEPEND_PKG), $(shell ${PKG-CONFIG} --cflags $(config)))
	LDFLAGS += $(foreach config, $(DEPEND_PKG), $(shell ${PKG-CONFIG} --libs $(config)))
endif