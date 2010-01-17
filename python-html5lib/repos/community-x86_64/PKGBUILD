# Contributor: Erol V. Aktay <e.aktay@gmail.com>
# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=python-html5lib
pkgver=0.11.1
pkgrel=3
pkgdesc="A HTML parser/tokenizer based on the WHATWG HTML5 spec"
arch=('i686' 'x86_64')
url="http://code.google.com/p/html5lib/"
license=('MIT')
depends=('python')
makedepends=('unzip' 'setuptools')
source=(http://html5lib.googlecode.com/files/html5lib-${pkgver}.zip
	LICENSE)

build() {
        cd ${srcdir}/html5lib-${pkgver}
        python setup.py install --root=${pkgdir} || return 1
	install -dm755 LICENSE ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE	
}
md5sums=('f0981fcec3d69789f12f52779c55fa29'
	 '838c366f69b72c5df05c96dff79b35f2')
