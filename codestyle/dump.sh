#!/bin/bash

## $1
## LLVM
## Google
## Chromium
## Mozilla
## WebKit
## Microsoft
clang-format --style=$1 -dump-config > $1.clang-format
