# $Id$
# Maintainer: BlackEagle < ike DOT devolder AT gmail DOT com >
# Maintainer: Sébastien Luttringer <seblu@aur.archlinux.org

pkgname=par2cmdline
pkgver=0.6.0
pkgrel=1
pkgdesc='A PAR 2.0 compatible file verification and repair tool'
url='https://github.com/BlackIkeEagle/par2cmdline'
license=('GPL2')
arch=('i686' 'x86_64')
source=("$pkgname-$pkgver.tar.gz::https://github.com/BlackIkeEagle/$pkgname/archive/v$pkgver.tar.gz")
sha256sums=('afa0b4f3f9e7ddace9f435c8a85e16e8a6ad4558129e831e41439da21f685374')

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
	export MAKEFLAGS="-j1"
	make check
}

package() {
	cd "$pkgname-$pkgver"
	make DESTDIR="$pkgdir" install
}

# vim:set ts=2 sw=2 et:
