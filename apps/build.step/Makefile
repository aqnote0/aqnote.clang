
MODULE_HOME=$(shell pwd)
BUILD_HOME=${MODULE_HOME}/build
BIN_HOME=${MODULE_HOME}/bin
DIST_HOME=${MODULE_HOME}/dist

TARGET = main
CFLAGS = -I/opt/aqnote/include
LDFLAS = -L/opt/aqnote/lib
COMPILE = -m64 -std=c99

all: pre_env ${TARGET}.app

pre_env:
	@mkdir ${BUILD_HOME}
	@mkdir ${BIN_HOME}
	@mkdir ${DIST_HOME}

${TARGET}.app: preprocess compile assembly link

preprocess:
	gcc -o ${BUILD_HOME}/${TARGET}.i -E src/${TARGET}.c ${CFLAGS}

compile:
	gcc -o ${BUILD_HOME}/${TARGET}.s -S ${BUILD_HOME}/${TARGET}.i ${COMPILE}

assembly:
	gcc -o ${BUILD_HOME}/${TARGET}.o -c ${BUILD_HOME}/${TARGET}.s

link:
	gcc -o ${BIN_HOME}/${TARGET}.app ${BUILD_HOME}/${TARGET}.o ${LDFLAS} 

clean:
	rm -rf ${BUILD_HOME} ${BIN_HOME} ${DIST_HOME}