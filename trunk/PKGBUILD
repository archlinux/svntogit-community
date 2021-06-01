# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=distlib
pkgbase='python-distlib'
pkgname=('python-distlib' 'python2-distlib')
pkgver=0.3.2
pkgrel=1
pkgdesc="Low-level components of distutils2/packaging"
arch=('any')
url="https://bitbucket.org/pypa/${_pkgname}"
license=('PSF')
makedepends=('python' 'python2')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.zip")
sha256sums=('106fef6dc37dd8c0e2c0a60d3fca3e77460a48907f335fa28420463a6f799736')
b2sums=('414d3852ac612cdd08a15e6cb82e56ba2afaeef02f1cb28d029d1de72e4929c498e9f69c36d65419caf1671bf7e06c4f38f20c4aef4b969ee490c70b03b49ce8')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    rm distlib/*.exe

}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
    python2 setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    PYTHONHASHSEED=0 python setup.py test
    python2 setup.py test
}

package_python-distlib() {
    depends=('python')

    cd "${srcdir}"/${_pkgname}-${pkgver}
    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
}

package_python2-distlib() {
    depends=('python2')

    cd "${srcdir}"/${_pkgname}-${pkgver}
    python2 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
}
