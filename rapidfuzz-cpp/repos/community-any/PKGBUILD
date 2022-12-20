# Maintainer:
# Contributor: Pekka Ristola <pekkarr [at] protonmail [dot] com>

pkgname=rapidfuzz-cpp
pkgver=1.10.4
pkgrel=1
pkgdesc='Rapid fuzzy string matching in C++ using the Levenshtein Distance'
arch=(any)
url='https://github.com/maxbachmann/rapidfuzz-cpp'
license=(MIT)
makedepends=(cmake)
source=(https://github.com/maxbachmann/rapidfuzz-cpp/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('84a1ea8759aaa5bc8587c26504421d6fd34ad2a8dc74bf469b0cc3cc6758e17a')

build() {
  cmake -B build -S $pkgname-$pkgver \
      -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
