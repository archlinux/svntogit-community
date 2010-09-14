# Maintainer: Hugo Doria <hugo@archlinux.org>
# Contributor: Wilson Pinto Júnior <n3rd3x@guake-terminal.org>

pkgname=python-certtool
pkgver=0.1
pkgrel=7
pkgdesc="Python tool to generate tls keys"
arch=('i686' 'x86_64')
url="http://python-certtool.sf.net"
depends=('python2' 'gnutls')
license=('LGPL')
source=(http://downloads.sourceforge.net/sourceforge/${pkgname}/${pkgname}-${pkgver}.tar.gz)
md5sums=('c8bf7d0b3274737bf08a6fb5a3cf035b')

build() {
  cd "${srcdir}/${pkgname}"
  python2 setup.py install --root="${pkgdir}" -O1
}

