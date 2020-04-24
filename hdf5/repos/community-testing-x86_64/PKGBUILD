# Maintainer: Ronald van Haren <ronald.archlinux.org>
# Maintainer: Bruno Pagani <archange@archlinux.org>
# Contributor: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: damir <damir@archlinux.org>
# Contributor: Tom K <tomk@runbox.com>

pkgname=hdf5
pkgver=1.12.0
pkgrel=2
pkgdesc="General purpose library and file format for storing scientific data"
arch=(x86_64)
url="https://www.hdfgroup.org/hdf5"
license=(custom)
depends=(zlib libaec bash)
makedepends=(cmake time gcc-fortran)
replaces=(hdf5-cpp-fortran)
provides=(hdf5-cpp-fortran)
options=(staticlibs)
source=("https://support.hdfgroup.org/ftp/HDF5/releases/${pkgname}-${pkgver:0:4}/${pkgname}-${pkgver/_/-}/src/${pkgname}-${pkgver/_/-}.tar.bz2"
        hdf5-1.12.0-compat-1.6.patch)
sha256sums=('97906268640a6e9ce0cde703d5a71c9ac3092eded729591279bf2e3ca9765f61'
            '72ad497c56760bb3af8193c88d3fa264125829850b843697de55d934c56f7f44')

build() {
    # Crazy workaround: run CMake to generate pkg-config file
    mkdir -p build && cd build
    cmake ../${pkgname}-${pkgver/_/-} \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_BUILD_TYPE=Release \
        -DHDF5_BUILD_HL_LIB=ON \
        -DHDF5_BUILD_CPP_LIB=ON \
        -DHDF5_BUILD_FORTRAN=ON \
        -DHDF5_ENABLE_Z_LIB_SUPPORT=ON \
        -DHDF5_ENABLE_SZIP_SUPPORT=ON \
        -DHDF5_ENABLE_SZIP_ENCODING=ON
    # But don’t build with it, it’s quite broken
    cd ../${pkgname}-${pkgver/_/-}
    ./configure \
        --prefix=/usr \
        --docdir=/usr/share/doc/hdf5/ \
        --with-examplesdir='${DESTDIR}/${prefix}/share/doc/hdf5/examples' \
        --enable-static \
        --disable-sharedlib-rpath \
        --enable-build-mode=production \
        --enable-hl \
        --enable-cxx \
        --enable-fortran \
        --with-pic \
        --with-zlib \
        --with-szlib
    make
}

check() {
    cd ${pkgname}-${pkgver/_/-}
    # Without this, checks are failing with messages like “error while loading shared libraries: libhdf5.so.101: cannot open shared object file: No such file or directory”
    export LD_LIBRARY_PATH="${srcdir}"/${pkgname}-${pkgver/_/-}/src/.libs/
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":"${srcdir}"/${pkgname}-${pkgver/_/-}/c++/src/.libs/
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":"${srcdir}"/${pkgname}-${pkgver/_/-}/fortran/src/.libs/
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":"${srcdir}"/${pkgname}-${pkgver/_/-}/hl/src/.libs/
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":"${srcdir}"/${pkgname}-${pkgver/_/-}/hl/c++/src/.libs/
    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH":"${srcdir}"/${pkgname}-${pkgver/_/-}/hl/fortran/src/.libs/
    make check
}

package() {
    cd ${pkgname}-${pkgver/_/-}
    make DESTDIR="${pkgdir}" install
    install -Dm644 COPYING -t "${pkgdir}"/usr/share/licenses/${pkgname}
    # Install pkg-config files from CMake tree
    install -Dm644 ../build/CMakeFiles/hdf5{,_hl}{,_cpp}-${pkgver}.pc -t "${pkgdir}"/usr/lib/pkgconfig/
    # Fix 1.6 compatibility for h5py
    cd "${pkgdir}"/usr/include/
    patch -p1 -i "${srcdir}"/hdf5-1.12.0-compat-1.6.patch
}
