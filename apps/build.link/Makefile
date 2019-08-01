
MODULE_HOME=$(shell pwd)
BUILD_HOME=${MODULE_HOME}/build
BUILD_BIN=${BUILD_HOME}/bin
BUILD_LIB=${BUILD_HOME}/lib
DIST_HOME=${MODULE_HOME}/dist

all: pre_env main.app

pre_env: 
	@mkdir -p ${BUILD_HOME} 2>&1 >/dev/null
	@mkdir -p ${BUILD_BIN} 2>&1 >/dev/null
	@mkdir -p ${BUILD_LIB} 2>&1 >/dev/null
	@mkdir -p ${DIST_HOME} 2>&1 >/dev/null

main.app: main.o libfoo.so
	@cd ${BUILD_HOME}; \
	gcc -o ${BUILD_BIN}/$@ $< -Wl,-rpath='$$ORIGIN/../lib' -L./lib -lfoo; \
	cd - 2>&1 >/dev/null;

main.o: src/main.c
	gcc -o $(BUILD_HOME)/$@ $< -g -Wall -c

libfoo.so: lib/foo.c
	gcc -o $(BUILD_LIB)/$@ $< -g -Wall -fPIC -shared

dist: main.app
	@cd ${BUILD_HOME}; \
	find . \( -name '*.git' -o -name '*.bak' -o -name "*.o" \) -prune -o -print | \
		cpio -pu ${DIST_HOME}; \
	cd -;

clean:
	@rm -rf ${BUILD_BIN} ${BUILD_LIB} ${BUILD_HOME} ${DIST_HOME}