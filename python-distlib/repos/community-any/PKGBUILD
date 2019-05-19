# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=distlib
pkgbase='python-distlib'
pkgname=('python-distlib' 'python2-distlib')
pkgver=0.2.9
pkgrel=1
pkgdesc="Low-level components of distutils2/packaging"
arch=('any')
url="https://bitbucket.org/pypa/${_pkgname}"
license=('PSF')
makedepends=('python' 'python2')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.zip")
sha256sums=('f59db0ed3ef8248badfee5270eca6311de3b562c5b52fe140a53c2145e242cfd')
b2sums=('378a6f8caf1c45cda638e099c4631934310c152753a8f56437362f185309599ca2f33e6509c4643dfe6cab1834594efc000e625a6c649fa40ab1fb041546546c')

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
