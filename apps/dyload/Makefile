#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20181210
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

# Constant
MODULE_NAME 		= dyload
MODULE_INTRODUCE 	=

# Depends
MODULE_DEPENDS_PROJ 		=
MODULE_DEPENDS_PKG			=
MODULE_DEPENDS_NONSTD_PATH 	=
MODULE_DEPENDS_NONSTD_FILE	=

# Compile
MODULE_COMPILER 	= cpp
MODULE_BUILD 		= DEBUG
MODULE_OUTPUT 		= $(MODULE_NAME).app

## module structure
INC_DIR		:= include
SRC_DIR		:= src
LIB_DIR		:= lib
BIN_DIR 	:= bin
BUILD_DIR 	:= build
DEPENDS_DIR := depends

## get cpp source file
CPP_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(CPP_SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

## add Binary Depends
DEPENDS = $(shell ls depends 2>/dev/null)
ifneq "" "$(DEPENDS)"
	CFLAGS += $(foreach module, $(DEPENDS), -I$(DEPENDS_DIR)/${module}/include)
	LDFLAGS += $(foreach module, $(DEPENDS), -L$(DEPENDS_DIR)/${module}/lib)
	LDFLAGS += $(foreach module, $(DEPENDS), -l$(module))
endif

LDFLAGS += -ldl -Wl,-rpath=depends/so1/lib -Wl,-rpath=depends/so2/lib

BUILD = RELEASE
ifeq "DEBUG" "${MODULE_BUILD}"
	BUILD = DEBUG
endif

.PHONY: all
all: $(BUILD)

.PHONY: RELEASE
RELEASE: CFLAGS += -O2 -D NDEBUG -Wall #-fwhole-program
RELEASE: $(MODULE_OUTPUT)

.PHONY: DEBUG
DEBUG: CFLAGS += -O0 -D_DEBUG -Wall -g -D_DEBUG=1
DEBUG: $(MODULE_OUTPUT)

$(MODULE_NAME).app: $(OBJECTS)
	${MAKE} -C depends/so1 all
	${MAKE} -C depends/so2 all
	@mkdir -p bin
	g++ -o bin/$@ $(OBJECTS) $(LDFLAGS)

## compile .cpp file
$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	g++ -o $@ -c $< -std=c++11 ${CFLAGS}

.PHONY: clean
clean:
	@$(RM) -rf $(BUILD_DIR)
	@$(RM) -rf $(BIN_DIR)

# # Constant
# MODULE_NAME = dyload
# MODULE_INTRODUCE =

# # Depends
# MODULE_DEPENDS_PROJ 		=
# MODULE_DEPENDS_PKG			=
# MODULE_DEPENDS_NONSTD_PATH 	=
# MODULE_DEPENDS_NONSTD_FILE	=

# # Compile
# MODULE_COMPILER = cpp
# MODULE_BUILD = DEBUG
# MODULE_OUTPUT = $(MODULE_NAME).app

# modules = so1 so2

# COMPILER = g++

# .PHONY: all
# all: $(MODULE_OUTPUT)

# .PHONY: $(modules)
# $(modules):
# 	$(MAKE) -C $@ all

# $(MODULE_OUTPUT): src/main.o $(modules)
# 	$(COMPILER) -o $@ src/main.o -L./so1 -lso1 -L./so2 -lso2 -ldl -Wl,-rpath=./so1 -Wl,-rpath=./so2

# ## compile .cpp file
# %.o : %.cpp
# 	${COMPILER} -o $@ -c $< -std=c++11 ${CFLAGS}

# .PHONY:clean
# clean: cleanmodule
# 	rm src/main.o main.app

# .PHONY: cleanmodule
# cleanmodule:
# 	@for module in ${modules}; do \
# 		${MAKE} -C $$module clean; \
# 	done
