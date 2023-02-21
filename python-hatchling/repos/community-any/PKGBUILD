# Maintainer: Santiago Torres-Arias <santiago @ usualplace>
# Contributor: Kaizhao Zhang <zhangkaizhao@gmail.com>

pkgname=python-hatchling
pkgver=1.13.0
pkgrel=1
pkgdesc="A modern project, package, and virtual env manager (backend)"
arch=('any')
url="https://github.com/pypa/hatch"
license=('MIT')
depends=('python' 'python-tomli' 'python-packaging' 'python-pathspec'
        'python-pluggy' 'python-editables')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel')

_name=${pkgname/python-/}
source=(
  "${url}/archive/refs/tags/${_name}-v${pkgver}.tar.gz"
)
sha256sums=('41e17b56a28fd4e8f69e4cecbea4527491c761998aba8bd2fc71d0d9eadf66b8')

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
