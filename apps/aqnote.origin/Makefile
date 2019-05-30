

BUILD_HOME=build
BUILD_LIB=build/lib
BUILD_DIST=dist

main.app: main.o libfoo.so
	@cd ${BUILD_HOME}; \
	gcc -o main.app main.o -Wl,-rpath='$$ORIGIN/lib' -L./lib -lfoo; \
	cd - 2>&1 >/dev/null;

main.o: src/main.c
	@mkdir -p ${BUILD_HOME}
	gcc -g -Wall -c -o $(BUILD_HOME)/$@ $<

libfoo.so: lib/foo.c
	@mkdir -p $(BUILD_LIB)
	gcc -g -Wall -fPIC -shared -o $(BUILD_LIB)/libfoo.so lib/foo.c

dist: main.app
	@mkdir ${BUILD_DIST}
	cd ${BUILD_HOME}; \
		find . \( -name '*.app' -o -name "*.so" \) -print | \
		cpio -pu ../${BUILD_DIST}; \
	cd -;

clean:
	@rm -rf build

#find . \( -name '*.svn' -o -name '*.bak' -o -name '*.db' -o -name '*.ra*' -o -name "*.o" \) -prune -o -print | \
		cpio -pu ${BUILD_DIST}; \
