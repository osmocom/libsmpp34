#!/usr/bin/env bash

set -ex

osmo-clean-workspace.sh

autoreconf --install --force
./configure --enable-sanitize
$MAKE CFLAGS="-Werror" CPPFLAGS="-Werror"
# currently broken $MAKE $PARALLEL_MAKE
# currently broken $MAKE distcheck

osmo-clean-workspace.sh
