# Maintainer: Daniel Bermond <dbermond@archlinux.org>

_srcname=SPIRV-LLVM-Translator
pkgname=${_srcname,,}
_build=2
pkgver=8.0.1.${_build}
pkgrel=1
pkgdesc="Tool and a library for bi-directional translation between SPIR-V and LLVM IR"
arch=(x86_64)
url="https://github.com/KhronosGroup/SPIRV-LLVM-Translator/"
license=(custom)
makedepends=(cmake llvm)
_commit=94af090661d7c953c516c97a25ed053c744a0737
source=("${url}/archive/v${pkgver%.*}-${_build}/${pkgname}-${pkgver}.tar.gz"
        "${pkgname}-0001-Update-LowerOpenCL-pass.patch"::"https://raw.githubusercontent.com/intel/opencl-clang/${_commit}/patches/spirv/0001-Update-LowerOpenCL-pass-to-handle-new-blocks-represn.patch"
        "${pkgname}-0002-Remove-extra-semicolon.patch"::"https://raw.githubusercontent.com/intel/opencl-clang/${_commit}/patches/spirv/0002-Remove-extra-semicolon.patch")
sha256sums=('f145292872419cc101eee89ce1904be06ead2f5761816a22cb13788e5d394e19'
            '42ac9214fceec9b207201488c9eac899138cdbbd02e3fc56fe815e9bc3455046'
            'af9c341d4a2554e421965b40b0c7f87f4fc60b0522bbc6f0d6f2907d1ddd7ddb')

prepare() {
    mkdir -p build
    cd ${_srcname}-${pkgver%.*}-${_build}
    patch -Np1 -i ../${pkgname}-0001-Update-LowerOpenCL-pass.patch
    patch -Np1 -i ../${pkgname}-0002-Remove-extra-semicolon.patch
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
