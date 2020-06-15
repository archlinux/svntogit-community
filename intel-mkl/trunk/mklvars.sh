#!/bin/sh
#
# This little script pretends to be mklvars.sh but actually just exports some variables
# to directories precisely where Arch installs them. No point shipping the original
# mklvars.sh which wrongly guesses all the paths.

export "LD_LIBRARY_PATH=/opt/intel/mkl/lib/intel64_lin:${LD_LIBRARY_PATH}"
export "LIBRARY_PATH=/opt/intel/mkl/lib/intel64_lin:${LIBRARY_PATH}"
export "NLSPATH=/opt/intel/mkl/lib/intel64_lin/locale/%l_%t/%N:${NLSPATH}"
export "CPATH=/opt/intel/mkl/include:${CPATH}"
export "PKG_CONFIG_PATH=/usr/lib/pkgconfig:${PKG_CONFIG_PATH}"
