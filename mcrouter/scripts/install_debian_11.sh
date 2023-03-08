#!/usr/bin/env bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

MCROUTER_DIR=/usr/local/mcrouter
MCROUTER_REPO=https://github.com/lterlecki/mcrouter.git
PKG_DIR=$MCROUTER_DIR/pkgs
INSTALL_DIR=$MCROUTER_DIR/install

set -ex
mkdir -p $PKG_DIR
mkdir -p $INSTALL_DIR
mkdir -p $MCROUTER_DIR/repo
cd $MCROUTER_DIR/repo && git clone $MCROUTER_REPO
cd $MCROUTER_DIR/repo/mcrouter/mcrouter/scripts
BASE_DIR=$MCROUTER_DIR
TARGET="${2:-all}"

[ -n "$BASE_DIR" ] || ( echo "Base dir missing"; exit 1 )

apt-get update

# Note libzstd-dev is not available on stock Ubuntu 14.04 or 15.04.
apt-get install -y \
    autoconf \
    binutils-dev \
    bison \
    cmake \
    flex \
    g++ \
    gcc \
    git \
    libboost1.74-all-dev \
    libbz2-dev \
    libdouble-conversion-dev \
    libevent-dev \
    libgflags-dev \
    libgoogle-glog-dev \
    libjemalloc-dev \
    liblz4-dev \
    liblzma-dev \
    liblzma5 \
    libsnappy-dev \
    libsodium-dev \
    libssl-dev \
    libtool \
    libunwind8-dev \
    make \
    pkg-config \
    python-dev \
    ragel \
    sudo

cd "$(dirname "$0")" || ( echo "cd fail"; exit 1 )

./get_and_build_by_make.sh "Makefile_ubuntu-20.04" "$TARGET" "$BASE_DIR"

ln -s $MCROUTER_DIR/install/bin/mcrouter /usr/local/bin/mcrouter
