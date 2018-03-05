#!/usr/bin/env bash
export PATH="$PATH:$HOME/osmo-ci/scripts"

set -ex

osmo-clean-workspace.sh

autoreconf --install --force
./configure --enable-sanitize --enable-werror
$MAKE
$MAKE $PARALLEL_MAKE
$MAKE distcheck || cat-testlogs.sh

osmo-clean-workspace.sh
