# Contributor: Erol V. Aktay <e.aktay@gmail.com>
# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=python-html5lib
rpkgname=html5lib
pkgver=0.11.1
pkgrel=1
pkgdesc="A HTML parser/tokenizer based on the WHATWG HTML5 spec"
arch=('i686' 'x86_64')
url="http://code.google.com/p/html5lib/"
license=('MIT')
depends=('python')
makedepends=('unzip' 'setuptools')
source=(http://html5lib.googlecode.com/files/$rpkgname-$pkgver.zip)

build() {
        cd $startdir/src/$rpkgname-$pkgver
        python setup.py install --root=$startdir/pkg || return 1
}
md5sums=('f0981fcec3d69789f12f52779c55fa29')
