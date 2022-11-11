# Maintainer:
# Contributor: Pekka Ristola <pekkarr [at] protonmail [dot] com>

pkgname=rapidfuzz-cpp
pkgver=1.10.1
pkgrel=1
pkgdesc='Rapid fuzzy string matching in C++ using the Levenshtein Distance'
arch=(any)
url='https://github.com/maxbachmann/rapidfuzz-cpp'
license=(MIT)
makedepends=(cmake)
source=(https://github.com/maxbachmann/rapidfuzz-cpp/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('0319dfdf61db0e6795501f8fe167fe8f28f40ec0f35247f06028da0058911ceb')

build() {
  cmake -B build -S $pkgname-$pkgver \
      -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
