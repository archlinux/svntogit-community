# $Id$
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: rebel <novakpetya at yahoo dot co dot uk>

pkgname=qt5pas
_svnrevision=57934
pkgver=2.6.r57934
pkgrel=2
pkgdesc='Free Pascal Qt5 binding library updated by lazarus IDE'
arch=('x86_64')
url='https://svn.freepascal.org/svn/lazarus/trunk/lcl/interfaces/qt5/cbindings'
license=('LGPL3')
depends=('qt5-base' 'qt5-x11extras')
makedepends=('subversion')
source=("$pkgname::svn+https://svn.freepascal.org/svn/lazarus/trunk/lcl/interfaces/qt5/cbindings#revision=$_svnrevision")
sha512sums=('SKIP')

build() {
    cd "$pkgname"
	qmake-qt5 "QT += x11extras"
	make
}

package() {
    cd "$pkgname"
	make INSTALL_ROOT="$pkgdir" install
}
