# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: William Rea <sillywilly@gmail.com>

pkgname=gloox
pkgver=1.0.27
pkgrel=1
pkgdesc="C++ libraries for development of Jabber client/component/server"
arch=(x86_64)
url="https://camaya.net/gloox"
license=("GPL")
depends=('libidn' 'gnutls')
source=(https://camaya.net/download/gloox-$pkgver.tar.bz2)
sha256sums=('0b8b7371439bc58d9e51384b616c964b18b7b41b87af1b7855104380eda86ffb')

build() {
  cd "$srcdir"/gloox-$pkgver
  ./configure --prefix=/usr
  make
}

package() {
  cd "$srcdir"/gloox-$pkgver
  make DESTDIR="$pkgdir" install
}
