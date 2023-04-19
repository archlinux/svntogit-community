# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=zopfli
pkgver=1.0.3
pkgrel=3
pkgdesc="Compression algorithm library"
arch=(x86_64)
url="https://github.com/google/zopfli"
license=(Apache)
depends=(
  gcc-libs
  glibc
)
makedepends=(cmake)
provides=(
  libzopfli.so
  libzopflipng.so
)
source=($url/archive/$pkgname-$pkgver.tar.gz)
sha512sums=('362cbeee0b3f04a4c5da512f82671491f874d4ec7b693dca9724ae42123d7ac184cc4d5de1872b4f1fc938c97f79dfdb482f62d1fca4a17cff6d267f6021e8d2')
b2sums=('fed322e6d0baf8e9008e91fef4c459e8f67f0e7d62942469893d89b8ca39ace6d1ac68cbbc322e938e66a613ea9a36e3ae9f59550b5f4964107bec490a07038a')

build() {
  local cmake_options=(
    -B build
    -D CMAKE_INSTALL_PREFIX=/usr
    -D CMAKE_BUILD_TYPE=None
    -D ZOPFLI_BUILD_SHARED=ON
    -S $pkgname-$pkgname-$pkgver
    -W no-dev
  )

  cmake "${cmake_options[@]}"
  cmake --build build --verbose
}

check() {
  ctest --test-dir build --output-on-failure
}

package() {
  DESTDIR="$pkgdir" cmake --install build
  install -vDm 644 $pkgname-$pkgname-$pkgver/README* -t "$pkgdir/usr/share/doc/$pkgname/"
}

