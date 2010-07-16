# $Id$
# Contributor: dibblethewrecker <dibblethewrecker.at.jiwe.org>

pkgname=gquilt
pkgver=0.22
pkgrel=1
pkgdesc='A PyGTK GUI wrapper for quilt'
arch=('i686' 'x86_64')
url='http://users.bigpond.net.au/Peter-Williams/'
license=('GPL2')
depends=('quilt' 'pygtk')
source=("http://downloads.sourceforge.net/sourceforge/${pkgname}/${pkgname}-${pkgver}.tar.gz")
md5sums=('a15ad1c38cd26feba6a6b025fc91b213')

build() {
  cd ${pkgname}-${pkgver}

  sed -i 's|PREFIX=/usr/local|PREFIX=/usr|g' Makefile

  make
}

package() {
  cd ${pkgname}-${pkgver}

  make DESTDIR=${pkgdir} install
}
