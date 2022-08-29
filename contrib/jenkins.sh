#!/usr/bin/env bash
export PATH="$PATH:$HOME/osmo-ci/scripts"

set -ex

osmo-clean-workspace.sh

autoreconf --install --force
./configure --enable-sanitize --enable-werror
$MAKE $PARALLEL_MAKE
$MAKE distcheck || cat-testlogs.sh
$MAKE maintainer-clean

osmo-clean-workspace.sh
