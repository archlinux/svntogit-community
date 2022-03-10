# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Contributor: Dan Serban
# Contributor: Ross Melin <rdmelin@gmail.com>

pkgname=libfaketime
pkgver=0.9.10
pkgrel=1
pkgdesc='Report fake dates and times to programs without having to change the system-wide time.'
arch=('x86_64')
url='https://github.com/wolfcw/libfaketime'
license=('GPL2')
source=("https://github.com/wolfcw/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz")
md5sums=('bbeaa43f514fc8e637e5efdac53e2671')
options=(!lto)

build() {
  cd "${pkgname}-${pkgver}"
  make PREFIX=/usr
}

package() {
  cd "${pkgname}-${pkgver}"
  make PREFIX=/usr DESTDIR="${pkgdir}" install
}
