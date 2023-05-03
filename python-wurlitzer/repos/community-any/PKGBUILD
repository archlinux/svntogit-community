# Maintainer: Bruno Pagani <archange@archlinux.org>

_pkg=wurlitzer
pkgname=python-${_pkg}
pkgver=3.0.3
pkgrel=2
pkgdesc="Capture C-level stdout/stderr in Python"
arch=(any)
url="https://github.com/minrk/wurlitzer"
license=(MIT)
depends=(python)
makedepends=(python-setuptools)
checkdepends=(python-pytest)
source=(https://files.pythonhosted.org/packages/source/${_pkg::1}/${_pkg}/${_pkg}-${pkgver}.tar.gz)
sha256sums=('224f5fe70618be3872c05dfddc8c457191ec1870654596279fcc1edadebe3e5b')

build() {
  cd ${_pkg}-${pkgver}
  python setup.py build
}

check() {
  cd ${_pkg}-${pkgver}
  py.test test.py
}

package() {
  cd ${_pkg}-${pkgver}
  python setup.py install --root "${pkgdir}" --prefix=/usr --optimize=1 --skip-build
  install -Dm644 LICENSE -t "${pkgdir}"/usr/share/licenses/${pkgname}/
}
