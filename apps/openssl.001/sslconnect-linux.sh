
#!/bin/bash

OPENSSL_HOME=/usr/include
OPENSSL_INCLUDE=$OPENSSL_HOME/include
OPENSSL_LIBRARY=$OPENSSL_HOME/lib
CC=x86_64-linux-gnu-gcc

#export LDFLAGS="-L/usr/local/lib"

BIN=bin/sslconnect.app

$CC \
  -o $BIN  \
  src/sslconnect.c  \
  -m64  \
  -I$OPENSSL_INCLUDE \
  -L$OPENSSL_LIBRARY \
  -lcrypto -lssl



