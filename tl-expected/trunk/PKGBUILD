# Maintainer: Sven-Hendrik Haase <svenstaro@archlinux.org>
# Contributor: Viktor Schneider <info[at]vjs[dot]io>
pkgname=tl-expected
pkgver=1.1.0
pkgrel=1
pkgdesc="C++11/14/17 std::expected with functional-style extensions"
arch=('any')
url="https://github.com/TartanLlama/expected"
license=('custom:CC0')
makedepends=('cmake' 'git' 'ninja')
source=("expected-v${pkgver}.tar.gz::https://github.com/TartanLlama/expected/archive/v${pkgver}.tar.gz")
sha256sums=('1db357f46dd2b24447156aaf970c4c40a793ef12a8a9c2ad9e096d9801368df6')

build() {
  cd "expected-$pkgver"
  cmake \
      -B build \
      -G Ninja \
      -DCMAKE_INSTALL_PREFIX=/usr
  ninja -C build
}

package() {
  cd "expected-$pkgver"
  DESTDIR="$pkgdir/" ninja -C build install
  install -Dm644 COPYING "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
