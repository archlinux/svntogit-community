# Maintainer: Daniel Bermond <dbermond@archlinux.org>
# Maintainer: Bruno Pagani <archange@archlinux.org>

_srcname=SPIRV-LLVM-Translator
pkgname=${_srcname,,}
_build=1
pkgver=9.0.1.${_build}
pkgrel=1
pkgdesc="Tool and a library for bi-directional translation between SPIR-V and LLVM IR"
arch=(x86_64)
url="https://github.com/KhronosGroup/SPIRV-LLVM-Translator/"
license=(custom)
depends=(llvm-libs)
makedepends=(cmake llvm spirv-tools)
checkdepends=(python python-setuptools clang)
source=("${url}/archive/v${pkgver%.*}-${_build}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('44b3c4fdb640ac9b1072784f8c0e2e126ccc46a1c170c5f0a1a384c2942d9de6')

build() {
    # workaround to fix luxmark crashing issue: use -O0
    # https://github.com/intel/compute-runtime/issues/218
    cmake -B build -S ${_srcname}-${pkgver%.*}-${_build} \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_CXX_FLAGS_RELEASE='-O0' \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
        -DLLVM_INCLUDE_TESTS=ON \
        -DLLVM_EXTERNAL_LIT=/usr/bin/lit \
        -Wno-dev
    make -C build
}

check() {
    make -C build test
}

package() {
    make -C build DESTDIR="${pkgdir}" install
    install -Dm755 build/tools/llvm-spirv/llvm-spirv -t "${pkgdir}"/usr/bin
    install -Dm644 ${_srcname}-${pkgver%.*}-${_build}/LICENSE.TXT -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
