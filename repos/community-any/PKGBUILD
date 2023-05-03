# Maintainer: Santiago Torres-Arias <santiago @ usualplace>
# Contributor: Kaizhao Zhang <zhangkaizhao@gmail.com>

pkgname=python-hatchling
pkgver=1.14.0
pkgrel=4
pkgdesc="A modern project, package, and virtual env manager (backend)"
arch=('any')
url="https://github.com/pypa/hatch"
license=('MIT')
depends=('python' 'python-tomli' 'python-packaging' 'python-pathspec'
        'python-pluggy' 'python-editables' 'python-trove-classifiers')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')

_name=${pkgname/python-/}
source=(
  "${url}/archive/refs/tags/${_name}-v${pkgver}.tar.gz"
)
sha256sums=('5cde87f9c1a4841201c81c754df692a5ca250caa8956721c674f92aa904abcea')

build() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"
  python -m build --wheel --no-isolation backend
}

package() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"

  python -m installer --destdir="$pkgdir" backend/dist/*.whl
  install -Dm644 README.md "${pkgdir}/usr/share/doc/${pkgname}/README.md"
  install -Dm644 backend/LICENSE.txt "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.txt"
}
