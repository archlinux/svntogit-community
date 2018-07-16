# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Contributor: Daniel J Griffiths <ghost1227@archlinux.us>
# Contributor: Erol V. Aktay <e.aktay@gmail.com>

pkgbase=python-html5lib
pkgname=('python2-html5lib' 'python-html5lib')
pkgver=1.0.1
pkgrel=3
arch=('any')
url="https://github.com/html5lib"
license=('MIT')
makedepends=('python-setuptools' 'python2-setuptools' 'python-webencodings' 'python2-webencodings')
checkdepends=('python-six' 'python2-six' 'python-pytest-expect' 'python2-pytest-expect'
              'python-lxml' 'python2-lxml' 'python-mock' 'python2-mock')
_test_commit=c305da74fae50fb018870de7a042da36c1a93b65
source=("$pkgbase-$pkgver.tar.gz::https://github.com/html5lib/html5lib-python/archive/${pkgver}.tar.gz"
        "https://github.com/html5lib/html5lib-tests/archive/${_test_commit}.tar.gz")
sha256sums=('fabbebd6a55d07842087f13849076eeed350aa8bb6c9ec840f6a6aba9388db06'
            'cb261423c644b3469ac66926e290060b481371d0952995d270492fc761d0209a')

prepare() {
    cd "${srcdir}"/html5lib-python-${pkgver}

    rmdir html5lib/tests/testdata
    ln -sfT ../../../html5lib-tests-${_test_commit} html5lib/tests/testdata
}

build() {
    cd "${srcdir}"/html5lib-python-${pkgver}

    python setup.py build
    python2 setup.py build
}

check() {
    cd "${srcdir}"/html5lib-python-${pkgver}

    py.test
    py.test2
}

package_python-html5lib() {
    pkgdesc="A Python HTML parser/tokenizer based on the WHATWG HTML5 spec"
    depends=('python' 'python-six' 'python-webencodings')
    optdepends=('python-lxml: lxml treebuilder'
                'python-genshi: genshi treewalker')
    cd "${srcdir}"/html5lib-python-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm755 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

package_python2-html5lib() {
    pkgdesc="A Python2 HTML parser/tokenizer based on the WHATWG HTML5 spec"
    depends=('python2' 'python2-six' 'python2-webencodings')
    optdepends=('python2-lxml: lxml treebuilder'
                'python2-genshi: genshi treewalker')
    cd "${srcdir}"/html5lib-python-${pkgver}

    python2 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm755 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
