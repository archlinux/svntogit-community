# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=pytest-expect
pkgname='python-pytest-expect'
pkgver=1.1.0
pkgrel=10
pkgdesc="py.test plugin to store test expectations and mark tests based on them"
arch=('any')
url="https://github.com/gsnedders/${_pkgname}"
license=('MIT')
depends=('python-pytest' 'python-u-msgpack')
makedepends=('python-setuptools' 'python-pytest' 'python-u-msgpack')
source=("${_pkgname}-${pkgver}.tar.gz::${url}/archive/${pkgver}.tar.gz")
sha256sums=('8392093123dfc9807c28fee251e1d710aaed0d46ee77c7531528fb0a265eb798')

build() {
  cd "${srcdir}/${_pkgname}-${pkgver}"

  python setup.py build
}

package_python-pytest-expect() {
  cd "${srcdir}/${_pkgname}-${pkgver}"
  python setup.py install --root="${pkgdir}" --optimize=1 --skip-build

  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
