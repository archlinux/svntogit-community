# Contributor : Giedrius Slavinskas <giedrius25@gmail.com>

pkgname=python-babel
pkgver=0.9.5
pkgrel=1
pkgdesc="A collection of tools for internationalizing Python applications"
url="http://babel.edgewall.org/"
license=("BSD")
arch=('any')
depends=('python')
makedepends=('setuptools')
source=("http://ftp.edgewall.com/pub/babel/Babel-$pkgver.tar.gz")
md5sums=('05603f058644f81b9b5f75d0161a14dd')

build() {
  cd $startdir/src/Babel-${pkgver}
  python setup.py install --root=$startdir/pkg
  install -D -m0644 COPYING $startdir/pkg/usr/share/licenses/python-babel/COPYING
}
