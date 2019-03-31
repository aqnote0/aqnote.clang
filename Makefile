#
#     Title: 
#    Author: "Peng Li"<aqnote@aqnote.com>
#     CDate: 20181210
#     MDate:
# Copyright: http://aqnote.com/LICENSE
#
#

# Constant
export PROJECT_HOME 			= ${shell pwd}
export PROJECT_BUILD_HOME 		= ${PROJECT_HOME}/build
export PROJECT_APPS_HOME 		= ${PROJECT_HOME}/apps
export PROJECT_DOCS_HOME 		= ${PROJECT_HOME}/docs
export PROJECT_MODULES_HOME 	= ${PROJECT_HOME}/modules

modules = apps/helloworld								\
	modules/aqalgorithm apps/algorithm.test				\
	apps/dyload 										\
	apps/framebuffer 									\
	apps/gtk.lifecycle 									\
	apps/json-c.lifecycle 								\
	apps/kernel.mmap									\
	modules/moduleA modules/moduleB apps/multimodule 	\
	apps/std.stdlib 									\
	apps/thread.lifecycle 								\
	apps/thread.multithread 							\
	apps/thread.producer 								\
	apps/thread.threadpool								

# Variable
export MODULE_BUILD = DEBUG

.PHONY: all
all: ${modules}

.PHONY: $(modules)
$(modules):
	$(MAKE) -C $@ all

.PHONY: clean
clean:
	@for module in ${modules}; do \
		${MAKE} -C $$module clean; \
	done