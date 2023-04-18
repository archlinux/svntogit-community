# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Esclapion <esclapion at gmail.com>

pkgname=qastools
pkgver=0.23.0
pkgrel=2
pkgdesc="A collection of desktop applications for the Linux sound system ALSA."
arch=(x86_64)
url="https://gitlab.com/sebholt/qastools"
license=(GPL3)
groups=(pro-audio)
depends=(
  gcc-libs
  glibc
  hicolor-icon-theme
  qt5-base
  qt5-svg
)
makedepends=(
  alsa-lib
  cmake
  qt5-tools
  systemd-libs
)
source=($url/-/archive/v$pkgver/$pkgname-v$pkgver.tar.gz)
sha512sums=('79042a41a0ad37097d297175b899af73052953b7ae14058a1878e3145769db839b8bd4350bd36646d8436a3e8b37b64da7b3004bee3c7c7780d46a942af1d3b9')
b2sums=('c0ba54462e702411bee7a15a913617870488b1c9c2676e3c6f69d0648cff79cc1989e0f367953ba6f27b94c014c9b2fa7ef74ae4800d03b99bb8336ce4535d4a')

build() {
  local cmake_options=(
    -B build
    -D CMAKE_BUILD_TYPE=None
    -D CMAKE_INSTALL_PREFIX=/usr
    -S $pkgname-v$pkgver
    -W no-dev
  )

  cmake "${cmake_options[@]}"
  cmake --build build --verbose
}

check() {
  ctest --test-dir build --output-on-failure
}

package() {
  depends+=(
    alsa-lib libasound.so
    systemd-libs libudev.so
  )

  DESTDIR="$pkgdir" cmake --install build
  install -vDm 644 $pkgname-v$pkgver/{CHANGELOG,README.md,TODO} -t "$pkgdir/usr/share/doc/$pkgname/"
}

