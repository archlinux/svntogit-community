# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: George Rawlinson <george@rawlinson.net.nz>

_pkgname=poetry-core
pkgname=python-poetry-core
pkgver=1.0.0
pkgrel=2
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
sha256sums=('c8cff356f09b483cdbe752a18fa8a95716a55a225981e78410816659a9f82b87')
b2sums=('62fe73c44a91569c92ec5f422211adeae3b9fc28547a0e37fdbe73ea92bfd4a01bdf35a2f6fb3dbbc4fd3d3e219ad2cfc5594229482dafe46051ded6cb04dab0')

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
