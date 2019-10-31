# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=distlib
pkgbase='python-distlib'
pkgname=('python-distlib' 'python2-distlib')
pkgver=0.3.0
pkgrel=1
pkgdesc="Low-level components of distutils2/packaging"
arch=('any')
url="https://bitbucket.org/pypa/${_pkgname}"
license=('PSF')
makedepends=('python' 'python2')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.zip")
sha256sums=('2e166e231a26b36d6dfe35a48c4464346620f8645ed0ace01ee31822b288de21')
b2sums=('e90624e886a5c4c430c53ae621b845c23d8fa3e5e89557bd521516e2290997bacb930652a9cb430fc3144e609181bbaf20037bedcce39f8f3ab14eda41e4d853')

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
