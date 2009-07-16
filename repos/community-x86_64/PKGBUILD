# $Id: PKGBUILD,v 1.16 2009/05/11 04:01:36 abhidg Exp $
# Maintainer: Abhishek Dasgupta <abhidg@gmail.com>
# Previous Maintainer: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=1.23.1
pkgrel=2
pkgdesc="User friendly shell intended mostly for interactive use"
arch=('i686' 'x86_64')
url="http://fishshell.org/"
license=("GPL" "LGPL" "BSD" "MIT")
depends=('ncurses' 'bc')
makedepends=('doxygen')
install=fish.install
source=(http://fishshell.org/files/$pkgver/$pkgname-$pkgver.tar.bz2)

build() {
  cd "$srcdir/$pkgname-$pkgver"
  ./configure --prefix=/usr --sysconfdir=/etc  \
     --docdir=/usr/share/doc/fish --without-xsel
  make || return 1
  make DESTDIR="$pkgdir" install
  install -D -m644 user_doc/html/license.html "$pkgdir/usr/share/licenses/$pkgname/license.html"
}
md5sums=('ead6b7c6cdb21f35a3d4aa1d5fa596f1')
