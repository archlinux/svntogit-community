# Maintainer: Dave Reisner <dreisner@archlinux.org>
# Contributor: feydaykyn <feydaykyn@yahoo.fr>

pkgname=leveldb
pkgver=1.23
pkgrel=3
pkgdesc="A fast and lightweight key/value database library"
arch=('x86_64')
url="https://github.com/google/leveldb"
license=('BSD')
depends=('snappy')
makedepends=('cmake' 'gmock' 'benchmark')
source=("$pkgname-$pkgver.tar.gz::https://github.com/google/leveldb/archive/$pkgver.tar.gz"
        leveldb-unbundle-gtest-benchmark.patch)
sha256sums=('9a37f8a6174f09bd622bc723b55881dc541cd50747cbd08831c2a82d620f6d76'
            '4183dc3b5c17a0cb5fb66ada179b9bd2b43e997d3a9c854d19cf892ea6e524b9')

prepare() {
  patch -d $pkgname-$pkgver -p1 < leveldb-unbundle-gtest-benchmark.patch # Unbundle GTest and benchmark
  sed -e '/fno-rtti/d' -i $pkgname-$pkgver/CMakeLists.txt # Don't disable RTTI, needed for ceph
}

build() {
  cmake -B build -S $pkgname-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DBUILD_SHARED_LIBS=1
  cmake --build build
}

check() {
  cmake --build build --target test
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  # documentation
  install -dm755 "$pkgdir"/usr/share/doc/$pkgname
  cp -dr --no-preserve=ownership $pkgname-$pkgver/doc/* "$pkgdir"/usr/share/doc/$pkgname

  # license
  install -Dm644 $pkgname-$pkgver/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname
}
