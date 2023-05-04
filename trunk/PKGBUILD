# Maintainer: Santiago Torres-Arias <santiago @ usualplace>
# Contributor: Kaizhao Zhang <zhangkaizhao@gmail.com>

pkgname=python-hatchling
pkgver=1.14.1
pkgrel=1
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
sha256sums=('b6662b331e0546f20cb211f8c28328c88344c1bb7d70ec2c25fb6afdaff51260')

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
