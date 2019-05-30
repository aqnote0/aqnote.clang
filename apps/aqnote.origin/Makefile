
MODULE_HOME=$(shell pwd)
BUILD_HOME=$(MODULE_HOME)/build
BUILD_BIN=$(BUILD_HOME)/bin
BUILD_LIB=$(BUILD_HOME)/lib
DIST_HOME=$(MODULE_HOME)/dist

all: main.app

main.app: main.o libfoo.so
	@mkdir -p ${BUILD_BIN}
	@cd ${BUILD_HOME}; \
	gcc -o ${BUILD_BIN}/main.app main.o -Wl,-rpath='$$ORIGIN/../lib' -L./lib -lfoo; \
	cd - 2>&1 >/dev/null;

main.o: src/main.c
	@mkdir -p ${BUILD_HOME}
	gcc -g -Wall -c -o $(BUILD_HOME)/$@ $<

libfoo.so: lib/foo.c
	@mkdir -p $(BUILD_LIB)
	gcc -g -Wall -fPIC -shared -o $(BUILD_LIB)/libfoo.so lib/foo.c

dist: main.app
	@mkdir ${DIST_HOME}
	cd ${BUILD_HOME}; \
	find . \( -name '*.git' -o -name '*.bak' -o -name "*.o" \) -prune -o -print | \
		cpio -pu ${DIST_HOME}; \
	cd -;

clean:
	@rm -rf $(BUILD_HOME) $(DIST_HOME) 

#find . \( -name '*.svn' -o -name '*.bak' -o -name '*.db' -o -name '*.ra*' -o -name "*.o" \) -prune -o -print | \
		cpio -pu ${BUILD_DIST}; \
