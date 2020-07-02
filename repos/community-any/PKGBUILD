# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Contributor: Daniel J Griffiths <ghost1227@archlinux.us>
# Contributor: Erol V. Aktay <e.aktay@gmail.com>

pkgbase=python-html5lib
pkgname=('python2-html5lib' 'python-html5lib')
pkgver=1.1
pkgrel=1
arch=('any')
url="https://github.com/html5lib"
license=('MIT')
_deps=('six' 'webencodings')
makedepends=('python-setuptools' 'python2-setuptools' "${_deps[@]/#/python-}" "${_deps[@]/#/python2-}")
_checkdeps=('pytest' 'pytest-expect' 'lxml' 'mock')
checkdepends=("${_checkdeps[@]/#/python-}" "${_checkdeps[@]/#/python2-}")
_test_commit=c305da74fae50fb018870de7a042da36c1a93b65
source=("$pkgbase-$pkgver.tar.gz::https://github.com/html5lib/html5lib-python/archive/${pkgver}.tar.gz"
        "https://github.com/html5lib/html5lib-tests/archive/${_test_commit}.tar.gz")
sha256sums=('66e9e24a53c10c27abb6be8a3cf2cf55824c6ea1cef8570a633cb223ec46e894'
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
    depends=("${_deps[@]/#/python-}")
    optdepends=('python-lxml: lxml treebuilder'
                'python-genshi: genshi treewalker')
    cd "${srcdir}"/html5lib-python-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

package_python2-html5lib() {
    pkgdesc="A Python2 HTML parser/tokenizer based on the WHATWG HTML5 spec"
    depends=("${_deps[@]/#/python2-}")
    optdepends=('python2-lxml: lxml treebuilder'
                'python2-genshi: genshi treewalker')
    cd "${srcdir}"/html5lib-python-${pkgver}

    python2 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
