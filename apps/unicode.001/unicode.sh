#!/bin/bash

gcc -m64            \
  -static           \
  -std=c99          \
  -Iicu4c/include   \
  -Licu4c/lib/      \
  -o build/unicode  \
  src/unicode.c         

exit 0
