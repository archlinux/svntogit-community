# Maintainer:
# Contributor: Pekka Ristola <pekkarr [at] protonmail [dot] com>

pkgname=rapidfuzz-cpp
pkgver=1.3.0
pkgrel=1
pkgdesc='Rapid fuzzy string matching in C++ using the Levenshtein Distance'
arch=(any)
url='https://github.com/maxbachmann/rapidfuzz-cpp'
license=(MIT)
makedepends=(cmake)
source=(https://github.com/maxbachmann/rapidfuzz-cpp/archive/v$pkgver/$pkgname-$pkgver.tar.gz)
sha256sums=('83396e75c64cfb1752055277843e28344bf161ac797bb105831ce24bd97a25d1')

build() {
  cmake -B build -S $pkgname-$pkgver \
      -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
