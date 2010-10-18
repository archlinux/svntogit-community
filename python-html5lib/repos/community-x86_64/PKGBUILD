# Contributor: Erol V. Aktay <e.aktay@gmail.com>
# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=python-html5lib
pkgver=0.11.1
pkgrel=4
pkgdesc="A HTML parser/tokenizer based on the WHATWG HTML5 spec"
arch=('i686' 'x86_64')
url="http://code.google.com/p/html5lib/"
license=('MIT')
depends=('python2')
makedepends=('unzip' 'setuptools')
source=(http://html5lib.googlecode.com/files/html5lib-${pkgver}.zip
    LICENSE)
md5sums=('f0981fcec3d69789f12f52779c55fa29'
         '838c366f69b72c5df05c96dff79b35f2')

build() {
    /bin/true
}

package() {
    cd ${srcdir}/html5lib-${pkgver}

    python2 setup.py install --root=${pkgdir}
    install -dm755 LICENSE ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE  
}
