# Maintainer: Antonio Rojas <arojas@archlinux.org>

pkgname=coin-or-data-sample
pkgver=1.2.12
pkgrel=1
pkgdesc='COIN-OR Sample data'
arch=(any)
url='https://github.com/coin-or-tools/Data-Sample'
license=(EPL)
depends=()
makedepends=()
groups=(coin-or)
source=($pkgname-$pkgver.tar.gz::https://github.com/coin-or-tools/Data-Sample/archive/refs/tags/releases/$pkgver.tar.gz)
sha256sums=('e9e67c04adfbd85523890b346326b106075df615e922c229277e138dbcb77e64')

build() {
  cd Data-Sample-releases-$pkgver

  ./configure --prefix=/usr
  make
}

package() {
  cd Data-Sample-releases-$pkgver
  make DESTDIR="$pkgdir" install
}
