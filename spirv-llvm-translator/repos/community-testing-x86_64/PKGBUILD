# Maintainer: Daniel Bermond <dbermond@archlinux.org>
# Maintainer: Bruno Pagani <archange@archlinux.org>

_srcname=SPIRV-LLVM-Translator
pkgname=${_srcname,,}
pkgver=14.0.0.r1+ga16f3db3
pkgrel=1
pkgdesc="Tool and a library for bi-directional translation between SPIR-V and LLVM IR"
arch=(x86_64)
url="https://github.com/KhronosGroup/SPIRV-LLVM-Translator"
license=(custom)
depends=(llvm-libs spirv-tools)
makedepends=(git cmake llvm spirv-headers)
checkdepends=(python python-setuptools clang)
# Required by ISPC
_commit=a16f3db323862cc49d31135697309a3188a024a8
source=(git+${url}.git#commit=$_commit)
sha256sums=(SKIP)

pkgver() {
  cd ${_srcname}
  git describe --tags | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./;s/-/+/'
}

build() {
  cmake -B build -S ${_srcname} \
    -DBUILD_SHARED_LIBS=ON \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
    -DCMAKE_SKIP_RPATH=ON \
    -DLLVM_INCLUDE_TESTS=ON \
    -DLLVM_EXTERNAL_LIT=/usr/bin/lit \
    -DLLVM_EXTERNAL_SPIRV_HEADERS_SOURCE_DIR=/usr/include/spirv/ \
    -Wno-dev
  make -C build
}

check() {
  # https://github.com/KhronosGroup/SPIRV-LLVM-Translator/issues/1433
  LD_LIBRARY_PATH="${srcdir}/build/lib/SPIRV" make -C build test || echo "Tests failed"
}

package() {
  make -C build DESTDIR="${pkgdir}" install
  install -Dm755 build/tools/llvm-spirv/llvm-spirv -t "${pkgdir}"/usr/bin
  install -Dm644 ${_srcname}/LICENSE.TXT -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
