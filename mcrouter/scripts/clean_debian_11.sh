#!/usr/bin/env bash
# Copyright (c) Meta Platforms, Inc. and affiliates.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

set -ex
apt-get install -y libdouble-conversion3 libgflags2.2 \
    libboost-program-options1.74.0 libboost-filesystem1.74.0 \
    libboost-system1.74.0 libboost-regex1.74.0 libboost-thread1.74.0 \
    libboost-context1.74.0 libgoogle-glog0v5 libevent-2.1-7 libjemalloc2

apt-get purge -y gcc g++ ragel autoconf \
    git libtool python-dev libssl-dev libevent-dev \
    binutils-dev make libdouble-conversion-dev libgflags-dev \
    libgoogle-glog-dev libjemalloc-dev pkg-config cmake

apt-get purge -y 'libboost.*-dev'
apt-get autoremove --purge -y
apt-get autoclean -y
apt-get clean -y

if [[ "x$1" != "x" ]]; then
    PKG_DIR=$1/pkgs
    INSTALL_DIR=$1/install
    strip "$INSTALL_DIR"/bin/mcrouter
    rm -rf "$PKG_DIR"
    rm -rf "$INSTALL_DIR"/lib/*.a
    rm -rf "$INSTALL_DIR"/include
fi
