# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cleo
pkgname=python-cleo
pkgver=0.6.8
pkgrel=1
pkgdesc="create beautiful and testable command-line interfaces"
arch=('any')
url="https://github.com/sdispater/${_pkgname}"
license=('MIT')
depends=('python-pastel' 'python-pylev')
makedepends=('python-dephell' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-mock')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha256sums=('931262582db48d4b310e7bc0fdc2b08b62e083869be89dfa2de292378264ce47')
b2sums=('30b5f240abf6811d11c935b07ad4f853d7796573e6da935c81872d03f19ad616d57d846688e33ff872b2203a61432f4d77b5515e2c3b307457c0095550330e68')

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
