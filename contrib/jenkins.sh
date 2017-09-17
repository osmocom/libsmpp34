#!/usr/bin/env bash

set -ex

autoreconf --install --force
./configure
$MAKE CFLAGS="-Werror" CPPFLAGS="-Werror"
# currently broken $MAKE $PARALLEL_MAKE
# currently broken $MAKE distcheck
