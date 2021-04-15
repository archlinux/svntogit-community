# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: George Rawlinson <george@rawlinson.net.nz>

_pkgname=poetry-core
pkgname=python-poetry-core
pkgver=1.0.3
pkgrel=1
pkgdesc="Poetry PEP 517 Build Backend & Core Utilities"
arch=('any')
url="https://github.com/python-poetry/${_pkgname}"
license=('MIT')
_deps=('jsonschema' 'lark-parser' 'packaging' 'tomlkit')
depends=("${_deps[@]/#/python-}")
makedepends=('python-dephell')
checkdepends=('git' 'python-pytest' 'python-pytest-mock' 'python-virtualenv')
conflicts=('python-poetry<1.1.0')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha256sums=('b5a9f8284c685c638796a322ea868843da5e2094c664436e44061e6bcea367ea')
b2sums=('38f6ffcc0eca97db3de213ca5aca97c0c7d458e317b568094f6b3fdb276ebeae230c831f117d8e39c17757e72d78beed2bf1b3f7f40cab2971bb5882fd27ed85')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # remove vendored dependencies
    sed -i '/^__version__/!d' poetry/core/__init__.py
    rm -r poetry/core/_vendor

    # be a proper namespace, python3-only ;)
    rm poetry/__init__.py

    dephell deps convert --from pyproject.toml --to setup.py
}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # only works inside git repositories
    pytest \
        -k 'not test_default_with_excluded_data and not test_default_src_with_excluded_data'
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
