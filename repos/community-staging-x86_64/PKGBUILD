# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgname=coin-or-asl
pkgver=2.0.0
pkgrel=1
pkgdesc='COIN-OR autotools harness to build AMPL Solver Library'
arch=(x86_64)
url='https://github.com/coin-or-tools/ThirdParty-ASL/'
license=(MIT)
groups=(coin-or)
depends=(glibc)
source=($pkgname-$pkgver.tar.gz::https://github.com/coin-or-tools/ThirdParty-ASL/archive/releases/$pkgver.tar.gz
        https://coin-or-tools.github.io/ThirdParty-ASL/solvers-64919f75f.tgz)
sha256sums=('b617b6d46a2722189dedef7c8013f7e21ebe677fe34cc6b62fabb1639fd3a96d'
            'e212926d1d797701adc901ef18eaab6b15edd13f9281dd8c9266e3cdaf8c2dd3')

prepare() {
  cd ThirdParty-ASL-releases-$pkgver
  ln -s ../solvers .
}

build() {
  cd ThirdParty-ASL-releases-$pkgver
  ./configure --prefix=/usr --srcdir="$PWD"
  make
}
package() {
  cd ThirdParty-ASL-releases-$pkgver
  make DESTDIR="$pkgdir" install
}
