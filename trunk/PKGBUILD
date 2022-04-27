# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Ian Yang <doit.ian@gmail.com>

pkgname=google-glog
pkgver=0.6.0
pkgrel=1
pkgdesc="Logging library for C++"
arch=('x86_64')
license=('custom:BSD3')
url='https://github.com/google/glog'
depends=('gflags')
makedepends=('cmake')
source=("glog-$pkgver.tar.gz::https://github.com/google/glog/archive/v$pkgver.tar.gz")
sha512sums=('fd2c42583d0dd72c790a8cf888f328a64447c5fb9d99b2e2a3833d70c102cb0eb9ae874632c2732424cc86216c8a076a3e24b23a793eaddb5da8a1dc52ba9226')

build() {
  cmake -B build -S glog-$pkgver \
    -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build

  # Lazy way of dealing with conflicting man and info pages...
#  rm -rf "$pkgdir"/usr/share

  install -Dm644 glog-$pkgver/COPYING -t "$pkgdir"/usr/share/licenses/$pkgname
}
