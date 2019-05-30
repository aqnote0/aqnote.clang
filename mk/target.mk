#     Title: Module Structure
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20190527
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

###############################
## Input Variable
###############################
AQNOTE_MODULE_NAME 		= ${MODULE_NAME}
AQNOTE_MODULE_DEPS 		= ${MODULE_DEPS}
AQNOTE_MODULE_BUILD		= ${MODULE_BUILD}
AQNOTE_MODULE_TARGET	= ${MODULE_TARGET}
# AQNOTE_DEP_MODULES		= $(foreach module, $(DEPEND_MODULE_LIST), $(DEPEND_MODULE_$(module)_HOME))
# AQNOTE_DEP_THIRDS		= $(foreach module, $(DEPEND_THIRD_LIST), $(DEPEND_THIRD_$(module)_HOME))

AQNOTE_DEP_MODULES		= $(foreach module, $(DEPEND_MODULE_LIST), \
							$(if $(DEPEND_MODULE_$(module)_STATIC), \
								, $(DEPEND_MODULE_$(module)_HOME) \
							) 	\
						)
AQNOTE_DEP_THIRDS		= $(foreach module, $(DEPEND_THIRD_LIST), \
							$(if $(DEPEND_THIRD_$(module)_STATIC), \
								, $(DEPEND_THIRD_$(module)_HOME) \
							) 	\
						)

###############################
## TARGET
###############################
BUILD = RELEASE
ifeq "DEBUG" "${AQNOTE_MODULE_BUILD}"
	BUILD = DEBUG
endif

.PHONY: all
all: $(BUILD)

.PHONY: RELEASE
RELEASE: CFLAGS += -O2 -D NDEBUG -Wall #-fwhole-program
RELEASE: $(AQNOTE_MODULE_TARGET)

.PHONY: DEBUG
DEBUG: CFLAGS += -O0 -g -D_DEBUG -Wall
DEBUG: $(AQNOTE_MODULE_TARGET)

$(AQNOTE_MODULE_NAME).app: $(OBJECTS)
	@mkdir -p bin
	$(LINK) -o bin/$@ $(OBJECTS) $(LDFLAGS)

lib$(AQNOTE_MODULE_NAME).so: $(OBJECTS)
	@mkdir -p lib
	$(LINK) -o lib/$@ $(OBJECTS) $(LDFLAGS) -shared

lib$(AQNOTE_MODULE_NAME).a: $(OBJECTS)
	@mkdir -p lib
	${AR} $(ARFLAGS) lib/$@ $(OBJECTS)

${AQNOTE_MODULE_NAME}.dep:
	@echo $(AQNOTE_MODULE_DEPS)
	@for module in $(AQNOTE_MODULE_DEPS); do \
		${MAKE} -C $$module all; \
	done

## compile .c file
$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	${CC} -o $@ -c $< -std=c99 ${CFLAGS}

## compile .cpp file
$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	${CPP} -o $@ -c $< -std=c++11 ${CFLAGS}

.PHONY: clean
clean:
	@$(RM) -rf $(BUILD_DIR)
	@$(RM) -rf $(BINARY_DIR)
	@$(RM) -rf $(LIBRARY_DIR)
	@$(RM) -rf $(DIST_DIR)

.PHONY: dist
dist:
	@mkdir -p ${DIST_DIR}/lib
	@for module in $(AQNOTE_DEP_MODULES); do \
		cp -rf $$module/lib/*.so ${DIST_DIR}/lib; \
	done
	@for module in $(AQNOTE_DEP_THIRDS); do \
		cp -rf $$module/lib/*.so ${DIST_DIR}/lib; \
	done
	@if [ "${AQNOTE_MODULE_TARGET}" = "${AQNOTE_MODULE_NAME}.app" ]; \
	then \
		cp -rf ${BINARY_DIR} ${DIST_DIR}; \
	else \
		cp -rf ${LIBRARY_DIR} ${DIST_DIR}/lib; \
	fi

.PHONY: memcheck
memcheck:
	@valgrind --tool=memcheck --leak-check=full ./$(AQNOTE_MODULE_TARGET)

.PHONY: echo
echo:
	@echo $(LDFLAGS)