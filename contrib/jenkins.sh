#!/usr/bin/env bash

set -ex

osmo-clean-workspace.sh

autoreconf --install --force
./configure --enable-sanitize
$MAKE CFLAGS="-Werror" CPPFLAGS="-Werror"
$MAKE $PARALLEL_MAKE
$MAKE distcheck

osmo-clean-workspace.sh
