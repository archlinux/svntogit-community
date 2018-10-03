# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=distlib
pkgbase='python-distlib'
pkgname=('python-distlib' 'python2-distlib')
pkgver=0.2.8
pkgrel=1
pkgdesc="Low-level components of distutils2/packaging"
arch=('any')
url="https://bitbucket.org/pypa/${_pkgname}"
license=('PSF')
makedepends=('python' 'python2')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.zip")
sha256sums=('57977cd7d9ea27986ec62f425630e4ddb42efe651ff80bc58ed8dbc3c7c21f19')

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
