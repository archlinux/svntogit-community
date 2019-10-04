# Maintainer: Daniel Bermond <dbermond@archlinux.org>

_srcname=SPIRV-LLVM-Translator
pkgname=${_srcname,,}
_build=1
pkgver=9.0.0.${_build}
pkgrel=1
pkgdesc="Tool and a library for bi-directional translation between SPIR-V and LLVM IR"
arch=(x86_64)
url="https://github.com/KhronosGroup/SPIRV-LLVM-Translator/"
license=(custom)
makedepends=(cmake llvm)
source=("${url}/archive/v${pkgver%.*}-${_build}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('19eff5daedb2c1aac8ab8d64a9f8228976dbaad71b1c1a3d3cd4c17cccdb0e55')

prepare() {
    mkdir -p build
}

build() {
    cd build
    cmake ../${_srcname}-${pkgver%.*}-${_build} \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
        -Wno-dev
    make
}

package() {
    cd build
    make DESTDIR="${pkgdir}" install
    install -Dm644 ../${_srcname}-${pkgver%.*}-${_build}/LICENSE.TXT -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
