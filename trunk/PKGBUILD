# Maintainer:
# Contributor: Pekka Ristola <pekkarr [at] protonmail [dot] com>

pkgname=rapidfuzz-cpp
pkgver=1.4.0
pkgrel=1
pkgdesc='Rapid fuzzy string matching in C++ using the Levenshtein Distance'
arch=(any)
url='https://github.com/maxbachmann/rapidfuzz-cpp'
license=(MIT)
makedepends=(cmake)
source=(https://github.com/maxbachmann/rapidfuzz-cpp/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('3ba6a6739ab78a6c11eea3a33f3e0f2980fbf53a68dc414dfb4fcf995f17025e')

build() {
  cmake -B build -S $pkgname-$pkgver \
      -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
