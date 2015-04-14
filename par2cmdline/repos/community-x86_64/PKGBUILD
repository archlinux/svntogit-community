# vim:set ts=2 sw=2 et:
# $Id$
# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org

pkgname=par2cmdline
pkgver=0.6.12
pkgrel=1
pkgdesc='A PAR 2.0 compatible file verification and repair tool'
url='https://github.com/BlackIkeEagle/par2cmdline'
license=('GPL2')
arch=('i686' 'x86_64')
source=("$pkgname-$pkgver.tar.gz::https://github.com/BlackIkeEagle/$pkgname/archive/v$pkgver.tar.gz")
sha256sums=('1788aaab2cd7f760c4dc24c1d31a471a4b584fbbfa2a47f06f340b4d73480144')

build() {
	cd "$pkgname-$pkgver"
	aclocal
	automake --add-missing
	autoconf
	./configure --prefix=/usr
  make
}

check() {
	cd "$pkgname-$pkgver"
	make check
}

package() {
	cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir" install
}

