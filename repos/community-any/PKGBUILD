# Maintainer: Santiago Torres-Arias <santiago @ usualplace>
# Contributor: Kaizhao Zhang <zhangkaizhao@gmail.com>

pkgname=python-hatchling
pkgver=0.25.0
pkgrel=2
pkgdesc="A modern project, package, and virtual env manager (backend)"
arch=('any')
url="https://github.com/ofek/hatch"
license=('MIT')
depends=('python' 'python-tomli' 'python-packaging' 'python-pathspec'
        'python-pluggy' 'python-editables')
makedepends=('python-pip' 'python-build' 'python-setuptools')

_name=${pkgname/python-/}
source=(
  "${url}/archive/refs/tags/${_name}-v${pkgver}.tar.gz"
)
sha256sums=('43db08b88916d1f373cde6b154e7527407cd07bea707c1ff3200c42b58bf288e')

build() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"
  python -m build backend
}

package() {
  cd "${srcdir}/hatch-${_name}-v${pkgver}"

  install -Dm644 README.md "${pkgdir}/usr/share/doc/${pkgname}/README.md"
  install -Dm644 backend/LICENSE.txt "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE.txt"

  PIP_CONFIG_FILE=/dev/null pip install --isolated --root="${pkgdir}" \
            --ignore-installed --no-deps backend/dist/*.whl

}
