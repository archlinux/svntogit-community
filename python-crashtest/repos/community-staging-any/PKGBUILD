# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=crashtest
pkgname=python-crashtest
pkgver=0.3.1
pkgrel=3
pkgdesc="supposedly makes exceptions handling and inspection easier"
arch=('any')
url="https://github.com/sdispater/${_pkgname}"
license=('MIT')
depends=('python')
makedepends=('python-dephell' 'python-setuptools')
checkdepends=('python-pytest')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha256sums=('8070032b432b523ff7a6d03251f0553da1d0f7643a27cedc4cd7652e67e3b19e')
b2sums=('b90465ee736ec0d9c378ed16327fe5bbddf19066a64a2a9d1c454f38eac5321235cafeb20756b2018e1dfea0e07726696084b8965a2543edc5e9fe0d79c33db1')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    dephell deps convert --from pyproject.toml --to setup.py
}

build(){
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
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
