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

###############################
## DEPEND
###############################

LINK_STATIC_OPT = -Wl,-Bstatic
LINK_DYNAMIC_OPT = -Wl,-Bdynamic
LINK_DYNAMIC_OPT2 = -Wl,-rpath='$$ORIGIN/../lib'
COMMAND_LINK = $(foreach lib, $1,$(if $2,$2 -l$(lib),-l$(lib)))

### add Module Source Depends
ifneq "" "$(DEPEND_MODULE_LIST)"
	CFLAGS += $(foreach module, $(DEPEND_MODULE_LIST), -I$(DEPEND_MODULE_$(module)_HOME)/include)
	LDFLAGS += $(foreach module, $(DEPEND_MODULE_LIST), 							\
					-L$(DEPEND_MODULE_$(module)_HOME)/lib											\
					$(if $(DEPEND_MODULE_$(module)_STATIC), 										\
						$(call COMMAND_LINK, $(DEPEND_MODULE_$(module)_LIB), $(LINK_STATIC_OPT)), 	\
						$(call COMMAND_LINK, $(DEPEND_MODULE_$(module)_LIB), $(LINK_DYNAMIC_OPT2)) 	\
					)																				\
					$(if $(DEPEND_MODULE_$(module)_STATIC), $(LINK_DYNAMIC_OPT))					\
				)
endif

### add Third Party Depends
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


### add System STD Depends
ifneq "" "$(DEPEND_STD)"
	LDFLAGS += $(foreach lib, $(DEPEND_STD), -l${lib})
endif

### add System Dir Depends
ifneq "" "$(DEPEND_NONSTD)"
	CFLAGS += $(foreach module, $(DEPEND_NONSTD), -I$(DEPEND_$(module)_HOME)/include)
	LDFLAGS += $(foreach module, $(DEPEND_NONSTD), 							\
					-L$(DEPEND_$(module)_HOME)/lib											\
					$(if $(DEPEND_$(module)_STATIC), 										\
						$(call COMMAND_LINK, $(DEPEND_$(module)_LIB), $(LINK_STATIC_OPT)), 	\
						$(call COMMAND_LINK, $(DEPEND_$(module)_LIB)) \
					)																		\
					$(if $(DEPEND_$(module)_STATIC), $(LINK_DYNAMIC_OPT))					\
				)
endif

### add pkg-config
# export PKG_CONFIG_PATH=${DEPEND_PKG_CONFIG}
ifneq "" "$(DEPEND_PKG)"
	CFLAGS += $(foreach config, $(DEPEND_PKG), $(shell ${PKG-CONFIG} --cflags $(config)))
	LDFLAGS += $(foreach config, $(DEPEND_PKG), $(shell ${PKG-CONFIG} --libs $(config)))
endif