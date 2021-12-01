# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cachecontrol
pkgname=python-cachecontrol
# Before bumping, watch out for:
# https://github.com/ionrock/cachecontrol/issues/262
pkgver=0.12.6
pkgrel=4
epoch=1
pkgdesc="httplib2 caching for requests"
arch=('any')
url="https://github.com/ionrock/${_pkgname}"
license=('Apache')
depends=('python-msgpack' 'python-requests')
makedepends=('python-setuptools')
checkdepends=('python-mock' 'python-pytest' 'python-lockfile' 'python-cherrypy')
optdepends=('python-lockfile: for the FileCache')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/v${pkgver}.tar.gz"
        "0001-Remove-unnecessary-console-script.patch")
sha256sums=('2ec120838f445bff473cd8b8206ddae3650679142976927179743fabb876f3e3'
            'a2c93d4852887152027140bdd54030d5363876b02e5eabee6a018d4e946a87b1')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    patch -p1 -i ../0001-Remove-unnecessary-console-script.patch
}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python -m pytest
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}
    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
}
