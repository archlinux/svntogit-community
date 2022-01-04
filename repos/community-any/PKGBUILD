# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=distlib
pkgname='python-distlib'
pkgver=0.3.4
pkgrel=1
pkgdesc="Low-level components of distutils2/packaging"
arch=('any')
url="https://github.com/pypa/distlib/"
license=('PSF')
depends=('python')
makedepends=('python')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.zip")
sha256sums=('e4b58818180336dc9c529bfb9a0b58728ffc09ad92027a3f30b7cd91e3458579')
b2sums=('60cf55ae7ab704748c932ac313e4ebd3e2d2d7bc4b6ea19b7d489eb896f342636f8202a2911e90d695ccf0e8a74e042461f6a954db17e83780353b055563ad21')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    rm distlib/*.exe

}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py test || true
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}
    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
}
