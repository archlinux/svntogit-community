# Maintainer: Daniel Bermond <dbermond@archlinux.org>
# Maintainer: Bruno Pagani <archange@archlinux.org>

_srcname=SPIRV-LLVM-Translator
pkgname=${_srcname,,}
pkgver=11.0.0
pkgrel=1
pkgdesc="Tool and a library for bi-directional translation between SPIR-V and LLVM IR"
arch=(x86_64)
url="https://github.com/KhronosGroup/SPIRV-LLVM-Translator/"
license=(custom)
depends=(llvm-libs)
makedepends=(cmake llvm spirv-tools)
checkdepends=(python python-setuptools clang)
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('6464a722278d37fca783cb505caf44cc8473c22fd22ff6a5d07198bc92059c4f')

build() {
    cmake -B build -S ${_srcname}-${pkgver} \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
        -DCMAKE_SKIP_RPATH=ON \
        -DLLVM_INCLUDE_TESTS=ON \
        -DLLVM_EXTERNAL_LIT=/usr/bin/lit \
        -Wno-dev
    make -C build
}

check() {
    LD_LIBRARY_PATH="${srcdir}/build/lib/SPIRV" make -C build test
}

package() {
    make -C build DESTDIR="${pkgdir}" install
    install -Dm755 build/tools/llvm-spirv/llvm-spirv -t "${pkgdir}"/usr/bin
    install -Dm644 ${_srcname}-${pkgver}/LICENSE.TXT -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
