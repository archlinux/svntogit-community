# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cachecontrol
pkgbase=python-cachecontrol
pkgname=('python-cachecontrol' 'python2-cachecontrol')
pkgver=0.12.6
pkgrel=5
pkgdesc="httplib2 caching for requests"
arch=('any')
url="https://github.com/ionrock/${_pkgname}"
license=('Apache')
makedepends=('python-msgpack' 'python-requests' 'python2-msgpack' 'python2-requests'
             'python-setuptools' 'python2-setuptools')
checkdepends=('python-mock' 'python-pytest' 'python-lockfile' 'python-cherrypy')
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
    python2 setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python -m pytest
    # Ignore python2 tests
    #python2 -m pytest
}

package_python-cachecontrol() {
    depends=('python-msgpack' 'python-requests')
    optdepends=('python-lockfile: for the FileCache')

    cd "${srcdir}"/${_pkgname}-${pkgver}
    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
}

package_python2-cachecontrol() {
    depends=('python2-msgpack' 'python2-requests')

    cd "${srcdir}"/${_pkgname}-${pkgver}
    python2 setup.py install --root="${pkgdir}" --optimize=1 --skip-build
}
