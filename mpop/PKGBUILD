# Maintainer: Lukas Fleischer <archlinux at cryptocrack dot de>
# Contributor: Israel Herraiz <isra@herraiz.org>
# Contributor: Roberto Alsina <ralsina@kde.org>

pkgname=mpop
pkgver=1.0.28
pkgrel=2
pkgdesc="A small, fast POP3 client suitable as a fetchmail replacement"
arch=('i686' 'x86_64')
url="http://mpop.sourceforge.net/"
license=('GPL3')
depends=('gnutls' 'libidn')
install=mpop.install
source=("http://downloads.sourceforge.net/mpop/mpop-$pkgver.tar.bz2")
md5sums=('08301208b1f1a40bc5375fea61de3696')
options=(debug !strip)

build() {
  cd "$srcdir/mpop-$pkgver"

  ./configure --prefix=/usr --with-ssl=gnutls
  make
}

package() {
  cd "$srcdir/mpop-$pkgver"

  make DESTDIR="$pkgdir" install
  install -Dm644 doc/mpoprc.example "$pkgdir/usr/share/mpop/mpoprc.example"
}
