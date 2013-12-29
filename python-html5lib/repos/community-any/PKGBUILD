# Contributor: Erol V. Aktay <e.aktay@gmail.com>
# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgbase=python-html5lib
pkgname=('python2-html5lib' 'python-html5lib')
pkgver=0.999
pkgrel=1
arch=('any')
url="http://code.google.com/p/html5lib/"
license=('MIT')
makedepends=('python2' 'python' 'unzip')
source=(https://github.com/html5lib/html5lib-python/archive/${pkgver}.tar.gz
    LICENSE)
md5sums=('f74b320f10d74df9cca8a08b42cb278c'
         '838c366f69b72c5df05c96dff79b35f2')

build() {
    /bin/true
}

package_python-html5lib() {
pkgdesc="A Python HTML parser/tokenizer based on the WHATWG HTML5 spec"
depends=('python' 'python-six')
    cd ${srcdir}/html5lib-python-${pkgver}

    python3 setup.py install --root=${pkgdir}
    install -Dm755 $srcdir/LICENSE ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE  
}

package_python2-html5lib() {
depends=('python2')
pkgdesc="A Python2 HTML parser/tokenizer based on the WHATWG HTML5 spec"
    cd ${srcdir}/html5lib-python-${pkgver}

    python2 setup.py install --root=${pkgdir}
    install -Dm755 $srcdir/LICENSE ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE  
}
