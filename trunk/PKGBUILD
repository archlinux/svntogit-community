# Maintainer: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=cleo
pkgname=python-cleo
pkgver=0.8.1
pkgrel=1
pkgdesc="create beautiful and testable command-line interfaces"
arch=('any')
url="https://github.com/sdispater/${_pkgname}"
license=('MIT')
depends=('python-clikit')
makedepends=('python-dephell' 'python-setuptools')
checkdepends=('python-pytest' 'python-pytest-mock')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha256sums=('3ff6fe33d9e440dba4d9b0947e65ebebf95671d18d89b67bed1e1a09d2266bc1')
b2sums=('57971f6254a31ecf5101d89e96607b5915ab5138d727279d445172b89a10acd6b76619d344973fa2bdbc320866fa1dbdf05c889f4eca879839fa6bcbbad0af7c')

prepare() {
    cd ${_pkgname}-${pkgver}

    # poetry-generated setup.py are fatally broken, see:
    # https://github.com/sdispater/poetry/issues/866
    dephell deps convert --from pyproject.toml --to setup.py
}

build(){
    cd ${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd ${_pkgname}-${pkgver}

    python -m pytest
}

package() {
    cd ${_pkgname}-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}
