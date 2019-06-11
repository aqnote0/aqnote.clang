
#!/usr/local/bin/bash

OPENSSL_HOME=/usr/local/Cellar/openssl/1.0.2n
OPENSSL_INCLUDE=$OPENSSL_HOME/include
OPENSSL_LIBRARY=$OPENSSL_HOME/lib
CC=/usr/local/bin/gcc

#export LDFLAGS="-L/usr/local/lib"

BIN=build/sslconnect

$CC \
  sslconnect.c  \
  -I$OPENSSL_INCLUDE \
  -L$OPENSSL_LIBRARY \
  -lcrypto -lssl \
  -o $BIN   
#  -m32  \



