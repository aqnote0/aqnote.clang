#     Title: common used Makefile
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20180809
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

###############################
## MODULE STRUCTURE
###############################
export INC_DIR		:= include
export SRC_DIR		:= src
export LIB_DIR		:= lib
export BIN_DIR 	:= bin
export BUILD_DIR 	:= build
export DEPENDS_DIR := depends

###############################
## COMMAND
###############################
CC 		= gcc
CPP 	= g++
RM 		= rm -f
LINK 	= ld

COMPILER = $(CC)
ifeq "cpp" "${MODULE_COMPILER}"
	COMPILER = $(CPP)
	# LDFLAGS += -L/usr/lib/x86_64-linux-gnu -lstdc++
endif

## targets
TARGETS 	:= $(MODULE_OUTPUT)

BUILD = RELEASE
ifeq "DEBUG" "${MODULE_BUILD}"
	BUILD = DEBUG
endif

###############################
## SOURCE CODE
###############################
## get c source files
C_SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(C_SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

## get cpp source file
CPP_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS += $(CPP_SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

## add static and dynamic
# -L/usr/lib64/mysql \
 -Wl,-Bstatic -lmysqlclient \
 -Wl,-Bdynamic -lz -lcrypt -lnsl -lm \
 -L/usr/lib64 -lssl -lcrypto

###############################
## DEPEND
###############################
### add Current Module Include
CFLAGS += -I./include

### add Module Source Depends
ifneq "" "$(MODULE_DEPENDS_PROJ)"
	CFLAGS += $(foreach module, $(MODULE_DEPENDS_PROJ), -I${PROJECT_MODULES_HOME}/${module}/include)
	LDFLAGS += $(foreach module, $(MODULE_DEPENDS_PROJ), ${PROJECT_MODULES_HOME}/${module}/lib/lib$(module).a)
endif

# ### add Module Binary Depends
# DEPENDS = $(shell ls depends 2>/dev/null)
# ifneq "" "$(DEPENDS)"
# 	CFLAGS += $(foreach module, $(DEPENDS), -I$(DEPENDS_DIR)/${module}/include)
# 	LDFLAGS += $(foreach module, $(DEPENDS), $(DEPENDS_DIR)/${module}/lib/lib$(module).a)
# endif
DEPENDS = $(shell ls depends 2>/dev/null)
ifneq "" "$(DEPENDS)"
	MODULE_DEPS = $(foreach module, $(DEPENDS), $(DEPENDS_DIR)/${module})
endif


### add System STD Depends
ifneq "" "$(MODULE_DEPENDS_STD_LIST)"
	LDFLAGS += $(foreach lib, $(MODULE_DEPENDS_STD_LIST), -l${lib})
endif

### add System Dir Depends
#### 编译器直接调用版本
LINK_STATIC_OPT = -Wl,-Bstatic
LINK_DYNAMIC_OPT = -Wl,-Bdynamic
COMMAND_LINK = $(foreach lib, $1,$(if $2,$2 -l$(lib),-l$(lib)))
ifneq "" "$(MODULE_DEPENDS_NONSTD_LIST)"
	CFLAGS += $(foreach module, $(MODULE_DEPENDS_NONSTD_LIST), -I$(DEPEND_$(module)_HOME)/include)
	LDFLAGS += $(foreach module, $(MODULE_DEPENDS_NONSTD_LIST), 							\
					-L$(DEPEND_$(module)_HOME)/lib											\
					$(if $(DEPEND_$(module)_STATIC), 										\
						$(call COMMAND_LINK, $(DEPEND_$(module)_LIB), $(LINK_STATIC_OPT)), 	\
						$(call COMMAND_LINK, $(DEPEND_$(module)_LIB)) 						\
					)																		\
					$(if $(DEPEND_$(module)_STATIC), $(LINK_DYNAMIC_OPT), )					\
				)
endif

# COMMAND_LINK = $(foreach lib, $1,$(if $2,$2 -l$(lib),-l$(lib)))
# ifneq "" "$(MODULE_DEPENDS_NONSTD_LIST)"
# 	CFLAGS += $(foreach module, $(MODULE_DEPENDS_NONSTD_LIST), -I$(DEPEND_$(module)_HOME)/include)
# 	LDFLAGS += $(foreach module, $(MODULE_DEPENDS_NONSTD_LIST), 							\
# 					$(if $(DEPEND_$(module)_STATIC), 										\
# 						$(LINK_STATIC_OPT) -L$(DEPEND_$(module)_HOME)/lib $(call COMMAND_LINK, $(DEPEND_$(module)_LIB)), \
# 					 	$(LINK_DYNAMIC_OPT) -L$(DEPEND_$(module)_HOME)/lib $(call COMMAND_LINK, $(DEPEND_$(module)_LIB)) \
# 					)																		\
# 					$(if $(DEPEND_$(module)_STATIC), $(LINK_DYNAMIC_OPT)) \
# 				)
# endif
# #### 链接器直接调用版本
# LINK_STATIC = -Bstatic
# LINK_DYNAMIC = -Bdynamic
# ifneq "" "$(MODULE_DEPENDS_NONSTD_LIST)"
# 	CFLAGS += $(foreach module, $(MODULE_DEPENDS_NONSTD_LIST), -I$(DEPEND_$(module)_HOME)/include)
# 	LDFLAGS += $(foreach module, $(MODULE_DEPENDS_NONSTD_LIST), 					\
# 					-L$(DEPEND_$(module)_HOME)/lib									\
# 					$(if $(DEPEND_$(module)_STATIC),								\
# 						$(foreach lib, $(DEPEND_$(module)_LIB), -Bstatic -l$(lib)),	\
# 						$(foreach lib, $(DEPEND_$(module)_LIB), -l$(lib))			\
# 					)	\
# 					$(if $(DEPEND_$(module)_STATIC), $(LINK_DYNAMIC) , )	\
# 				)
# endif

### add pkg-config
# export PKG_CONFIG_PATH=${MODULE_DEPENDS_PKG_CONFIG}
ifneq "" "$(MODULE_DEPENDS_PKG)"
	CFLAGS += $(foreach config, $(MODULE_DEPENDS_PKG), $(shell pkg-config --cflags $(config))) 
	LDFLAGS += $(foreach config, $(MODULE_DEPENDS_PKG), $(shell pkg-config --libs $(config)))
endif


###############################
## TARGET
###############################
.PHONY: all
all: $(BUILD)

.PHONY: RELEASE
RELEASE: CFLAGS += -O2 -D NDEBUG -Wall #-fwhole-program
RELEASE: $(TARGETS)

.PHONY: DEBUG
DEBUG: CFLAGS += -O0 -g -D_DEBUG -Wall
DEBUG: $(TARGETS)

$(MODULE_NAME).app: $(OBJECTS)
	@mkdir -p bin
	$(COMPILER) -o bin/$@ $(OBJECTS) $(LDFLAGS)

lib$(MODULE_NAME).so: $(OBJECTS)
	@mkdir -p lib
	$(LINK) -o lib/$@ $(OBJECTS) $(LDFLAGS) -shared

lib$(MODULE_NAME).a: $(OBJECTS)
	@mkdir -p lib
	ar $(ARFLAGS) lib/$@ $(OBJECTS)

${MODULE_NAME}.dep:
	@echo $(MODULE_DEPS)
	@for module in $(MODULE_DEPS); do \
		${MAKE} -C $$module all; \
	done

## compile .c file
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	${CC} -o $@ -c $< -std=c99 ${CFLAGS}

## compile .cpp file
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	${CPP} -o $@ -c $< -std=c++11 ${CFLAGS}

.PHONY: clean
clean:
	@$(RM) -rf $(BUILD_DIR)
	@$(RM) -rf $(BIN_DIR)
	@$(RM) -rf $(LIB_DIR)

.PHONY: memcheck
memcheck:
	@valgrind --tool=memcheck --leak-check=full ./$(TARGETS)

.PHONY: echo
echo:
	@echo $(LDFLAGS)