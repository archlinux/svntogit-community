# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgname=dontpanic
pkgver=1.02
pkgrel=2
pkgdesc='libdontpanic - used for testing Alien::Base'
arch=('x86_64')
url='https://github.com/Perl5-Alien/dontpanic'
license=('GPL')
depends=('glibc')
source=("$pkgname-$pkgver.tar.gz::https://github.com/Perl5-Alien/dontpanic/archive/$pkgver.tar.gz")
sha512sums=('e260a3c27427f838b9228d096be63be86016bdaee1482a22d71611ba029ecab5666dde8d684b761507118842158e38a2181a89bcc7dde259ccaafcb1c019ed58')

build() {
  cd dontpanic-$pkgver
  ./autogen.sh
  ./configure --prefix=/usr
  make
}

package() {
  cd dontpanic-$pkgver
  make DESTDIR="$pkgdir" install
}
