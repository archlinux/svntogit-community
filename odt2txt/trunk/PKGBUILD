# Contributor: Vladimir Chizhov <jagoterr@gmail.com>

pkgname=odt2txt
pkgver=0.4
pkgrel=1
pkgdesc="extracts the text out of OpenDocument Texts"
url="http://stosberg.net/odt2txt/"
license="GPL-2"
arch=('i686' 'x86_64')
depends=()
makedepends=()
conflicts=()
replaces=()
backup=()
install=
source=(http://stosberg.net/odt2txt/$pkgname-$pkgver.tar.gz)
md5sums=('6fe3bd261ce2dde2810244bbe969bbc5')

build() {
  cd $startdir/src/$pkgname-$pkgver
  make || return 1
  mkdir -p $startdir/pkg/usr/bin/
  mkdir -p $startdir/pkg/usr/share/man/man1
  gzip $startdir/src/$pkgname-$pkgver/odt2txt.1
  install -D -m755 odt2txt $startdir/pkg/usr/bin/
  install -D -m644 odt2txt.1.gz $startdir/pkg/usr/share/man/man1
}

