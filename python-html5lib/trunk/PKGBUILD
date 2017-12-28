# Contributor: Erol V. Aktay <e.aktay@gmail.com>
# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgbase=python-html5lib
pkgname=('python2-html5lib' 'python-html5lib')
pkgver=1.0.1
pkgrel=1
arch=('any')
url="https://github.com/html5lib"
license=('MIT')
makedepends=('python2' 'python' 'unzip' 'python-webencodings' 'python2-webencodings'
             'python2-setuptools' 'python-setuptools')
checkdepends=('python-six' 'python2-six' 'python2-pytest' 'python-pytest'
              'python-lxml' 'python2-lxml' 'python-mock' 'python2-mock') 
source=($pkgbase-$pkgver.tar.gz::https://github.com/html5lib/html5lib-python/archive/${pkgver}.tar.gz
    LICENSE)
md5sums=('ef1146d400657a17d396fb21da5b24b8'
         '838c366f69b72c5df05c96dff79b35f2')

package_python-html5lib() {
pkgdesc="A Python HTML parser/tokenizer based on the WHATWG HTML5 spec"
depends=('python' 'python-six' 'python-webencodings')
    cd ${srcdir}/html5lib-python-${pkgver}

    python3 setup.py install --root=${pkgdir}
    install -Dm755 $srcdir/LICENSE ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE  
}

package_python2-html5lib() {
depends=('python2' 'python2-six' 'python2-webencodings')
pkgdesc="A Python2 HTML parser/tokenizer based on the WHATWG HTML5 spec"
    cd ${srcdir}/html5lib-python-${pkgver}

    python2 setup.py install --root=${pkgdir}
    install -Dm755 $srcdir/LICENSE ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE  
}

check() {
    cd ${srcdir}/html5lib-python-${pkgver}/html5lib/tests
}
