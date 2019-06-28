# Maintainer: Daniel Bermond <dbermond@archlinux.org>

_srcname=SPIRV-LLVM-Translator
pkgname=${_srcname,,}
_build=1
pkgver=8.0.1.${_build}
pkgrel=1
pkgdesc="Tool and a library for bi-directional translation between SPIR-V and LLVM IR"
arch=(x86_64)
url="https://github.com/KhronosGroup/SPIRV-LLVM-Translator/"
license=(custom)
makedepends=(cmake llvm)
source=("${url}/archive/v${pkgver%.*}-${_build}/${pkgname}-${pkgver}.tar.gz"
        0001-Update-LowerOpenCL-pass-to-handle-new-blocks-represn.patch)
sha256sums=('3947761445e93a7049f75d133ea6ea4aa620feb9b09f0bfd006ec2ffcb0b00ab'
            'd3f477a6e7f4ab5ae2af8e50ec8cfc36f184392c119160f281bb66da758f3e25')

prepare() {
    mkdir -p build
    cd ${_srcname}-${pkgver%.*}-${_build}
    patch -Np1 -i ../0001-Update-LowerOpenCL-pass-to-handle-new-blocks-represn.patch
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
