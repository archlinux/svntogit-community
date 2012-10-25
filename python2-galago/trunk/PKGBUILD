# $Id: PKGBUILD 66128 2012-02-23 01:37:06Z spupykin $
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python2-galago
pkgver=0.5.0
pkgrel=6
pkgdesc="A library of simple functions that are optimized for various CPUs"
arch=('i686' 'x86_64')
url="http://galago-project.org"
options=('!libtool')
license=('LGPL')
depends=('libgalago' 'pygtk')
source=(http://galago-project.org/files/releases/source/galago-python/galago-python-$pkgver.tar.bz2)
md5sums=('27be31fcf2886aa21823caec15dc34aa')

build() {
  cd $srcdir/galago-python-$pkgver
  ./configure --prefix=/usr
  make
  make DESTDIR=$pkgdir install
}
