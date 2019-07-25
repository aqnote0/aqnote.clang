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
export PROJECT_3RDPARTY_HOME	= ${PROJECT_HOME}/3rdparty
export PROJECT_MAKEFILE_HOME	= ${PROJECT_HOME}/mk

modules = apps/aqnote.test \
	apps/aqnote.origin \
	modules/aqnote_ta modules/aqnote_tb apps/aqnote.template	\
	modules/aqnote_mma modules/aqnote_mmb apps/aqnote.multimodule 	\
	modules/aqnote_algorithm apps/algorithm.test \
	apps/std.stdlib		\
	apps/std.assert		\
	apps/std.stdio \
	# apps/dyload \
	# apps/framebuffer \
	# apps/gtk.lifecycle 	\
	# apps/json-c.lifecycle 	\
	# apps/kernel.mmap	\
	# apps/thread.lifecycle \
	# apps/thread.multithread \
	# apps/thread.producer \
	# apps/thread.threadpool								

# Variable
export MODULE_BUILD = DEBUG

.PHONY: all
all: build dist

.PHONY: build
build: $(modules)

.PHONY: dist
dist: 
	@for module in ${modules}; do \
		${MAKE} -C $$module dist; \
	done

.PHONY: $(modules)
$(modules):
	$(MAKE) -C $@ all

.PHONY: clean
clean:
	@for module in ${modules}; do \
		${MAKE} -C $$module clean; \
	done