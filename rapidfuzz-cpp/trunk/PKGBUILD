# Maintainer:
# Contributor: Pekka Ristola <pekkarr [at] protonmail [dot] com>

pkgname=rapidfuzz-cpp
pkgver=1.2.0
pkgrel=1
pkgdesc='Rapid fuzzy string matching in C++ using the Levenshtein Distance'
arch=(any)
url='https://github.com/maxbachmann/rapidfuzz-cpp'
license=(MIT)
makedepends=(cmake)
source=(https://github.com/maxbachmann/rapidfuzz-cpp/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('1605635adfbeeddb578d8a6c1df0356f4334adb16a97e52fe86a1f10d3de16bc')

build() {
  cmake -B build -S $pkgname-$pkgver \
      -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
