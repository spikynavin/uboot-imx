#!/bin/sh
source ~/iwave-cc
make distclean
make mx6solosabreauto_config
make -j8
sync
