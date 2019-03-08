#!/bin/bash

gcc -static         \
  -std=c11          \
  -Iicu4c/include   \
  -Licu4c/lib/      \
  -o build/unicode  \
  -m64              \
  unicode.c         



exit 0
