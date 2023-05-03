# Maintainer: Bruno Pagani <archange@archlinux.org>

_pkg=pytest-order
pkgname=python-${_pkg}
pkgver=1.1.0
pkgrel=2
pkgdesc="pytest plugin that allows to customize the test execution order"
arch=(any)
url="https://github.com/pytest-dev/pytest-order/"
license=(MIT)
depends=(python-pytest)
makedepends=(python-setuptools)
checkdepends=(
    python-pytest-dependency
    python-pytest-mock
    python-pytest-xdist
)
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('b207d9ab0619a184ae22418d9ab7bc7cd43769a3334256c7c541114e998a0dc7')

build() {
  cd ${_pkg}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkg}-${pkgver}
  python -m venv --system-site-packages test-env
  test-env/bin/python setup.py install --skip-build
  test-env/bin/python /usr/bin/pytest -vv --color=yes
}

package() {
  cd ${_pkg}-${pkgver}
  python setup.py install --root=${pkgdir} --optimize=1 --skip-build
  install -Dm644 LICENSE -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
