# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: George Rawlinson <george@rawlinson.net.nz>

_pkgname=poetry-core
pkgname=python-poetry-core
pkgver=1.0.2
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
sha256sums=('fafe5585040b91e36a9ec1ea6ce0546701190453ba8207bd4b7ed03a2cffc227')
b2sums=('483acd560b11cd78570781c8be1d9fb56437c592c762fecc54302f83fed3596f09fad1a8d42f7ce243cf19d0fe315e4b0fe8a9c114da814875f19357dc4261b2')

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
