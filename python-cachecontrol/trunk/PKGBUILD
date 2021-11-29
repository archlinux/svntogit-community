# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cachecontrol
pkgname=python-cachecontrol
pkgver=0.12.10
pkgrel=1
pkgdesc="httplib2 caching for requests"
arch=('any')
url="https://github.com/ionrock/${_pkgname}"
license=('Apache')
depends=('python-msgpack' 'python-requests')
makedepends=('python-msgpack' 'python-requests' 'python-setuptools')
checkdepends=('python-mock' 'python-pytest' 'python-lockfile' 'python-cherrypy')
optdepends=('python-lockfile: for the FileCache')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/v${pkgver}.tar.gz")
sha256sums=('fc8bc1ecc67ac2946b79a6a79da57c8ad510517787afd3db997ca0d432e56e3d')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}
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
