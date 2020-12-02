# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cleo
pkgname=python-cleo
pkgver=0.7.6
pkgrel=4
pkgdesc="create beautiful and testable command-line interfaces"
arch=('any')
url="https://github.com/sdispater/${_pkgname}"
license=('MIT')
depends=('python-clikit')
makedepends=('python-dephell' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-mock')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha256sums=('844d732c3306745cd2ffb2bd79327155a303844e3f9111bd7b578d9dd79ad2f7')
b2sums=('592c4e2d877909ccddc814293bb346c90bc5f4426231bcf8aa8fdae24b2f3ef8531d3cafb77e6f294868a34f66c5bd83b31633917e5b9d37c54e68502cbacf03')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # poetry-generated setup.py are fatally broken, see:
    # https://github.com/sdispater/poetry/issues/866
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
